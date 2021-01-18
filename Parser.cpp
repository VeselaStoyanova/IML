#include "Parser.h"

Vector<string> splitToWords(istringstream *iss, char separator) 
{
	Vector<string> components;
	string s;
	while (getline(*iss, s, separator))
	{
		components.push_back(s.c_str());
	}
	return components;
}

Vector<double> Parser::parseContent(string content)
{
	istringstream iss(content);
	Vector<string> tagRows = splitToWords(&iss, '<');
	Vector<double> result;

	// Ако първият елемент не е '<'
	if (tagRows[0] != "") 
	{
		cout << "Input error. The file does not start with the symbol '<'" << endl;
		exit(1);
	}

	//Първият елемент е празен стринг и го изтриваме.
	tagRows.pop_front();			
	result = evaluateContent(tagRows);
	return result;
}

Vector<double> Parser::evaluateContent(Vector<string> tagRows)
{
	Stack<Tag> tags;
	Vector<double> result;

	for (auto it = tagRows.begin(); it != tagRows.end(); ++it) 
	{
		istringstream iss(*it);
		Vector<string> components = splitToWords(&iss, '>');

		string operAndArgum = components[0];
		bool isClosingTag = operAndArgum.length() > 0 && operAndArgum[0] == '/';

		Operation operation;
		string argument;

		if (isClosingTag) 
		{
			operation = parseClosingOperation(components[0]);
		}

		else 
		{
			operation = parseOperation(components[0]);
			argument = parseArgument(components[0], operation);
		}

		bool hasNumbers = components.length() > 1;
		Vector<double> numbers;
		if (hasNumbers)
		{
			numbers = parseNumbers(components[1]);
		}

		if (isClosingTag)
		{
			//Проверяваме дали имаме затварящ таг, но стекът от тагове е празен
			if (tags.empty())
			{
				cout << "There is an additional closing tag." << endl;
				exit(1);
			}
			Tag lastTag = tags.top();
			//Проверяваме дали операцията на затварящия таг е различна от тази на отварящия 
			if (operation != lastTag.getOperation()) 
			{
				cout << "The closing tag is different from the opening tag." << endl;
				exit(1);
			}

			//Взимаме най-горния елемент на стека и го пресмятаме
			result = lastTag.calculate();
			//После pop-ваме горния елемент
			tags.pop();
			//Проверяваме дали имаме още елементи в стека
			if (!tags.empty())
			{
				Tag newLastTag = tags.top();
				tags.pop();
				//Добавяме полученият до момента резултат
				newLastTag.addNumbers(result);
				newLastTag.addNumbers(numbers);
				tags.push(newLastTag);
			}
		}
		else
		{
			Tag tag = Tag(operation, argument, numbers);
			tags.push(tag);
		}
	}

	//Проверяваме дали имаме още елементи в стека, като вече сме стигнали до края на файла
	if (!tags.empty())
	{
		cout << "The last closing tag is missing." << endl;
		exit(1);
	}

	return result;
}

Operation Parser::parseClosingOperation(string operAndArgum)
{
	istringstream iss(operAndArgum.substr(1));
	Vector<string> components = splitToWords(&iss, ' ');

	return switchOperation(components[0]);
}

Operation Parser::parseOperation(string operAndArgum)
{
	istringstream iss(operAndArgum);
	Vector<string> components = splitToWords(&iss, ' ');

	return switchOperation(components[0]);
}

string Parser::parseArgument(string operAndArgum, Operation operation)
{
	//Проверяваме дали функциите, които трябва да имат аргумент, го имат
	bool needsArgument = operation == MAP_INC || operation == MAP_MLT || operation == SRT_ORD || operation == SRT_SLC;

	istringstream iss(operAndArgum);
	Vector<string> components = splitToWords(&iss, ' ');
	
	bool hasArgument = components.length() > 1;

	//Проверка, ако трябва да има аргумент, но няма
	if (needsArgument && !hasArgument)
	{
		cout << "The required argument for the operation " << operation << " is missing." << endl;
		exit(1);
	}

	//Проверка, ако не трябва да има аргумент, но има
	if (!needsArgument && hasArgument)
	{
		cout << "There is a redundant argument for the operation " << operation << " . " << endl;
		exit(1);
	}

	//Проверка, ако трябва да има аргумент и има
	if (needsArgument && hasArgument)
	{
		string argument = components[1];
		argument.erase(remove(argument.begin(), argument.end(), '\"'), argument.end());
		return argument;
	}

	return "";
}

bool is_number(const string& s)
{
	char* endptr = 0;
	const char* c = s.c_str();
	strtod(c, &endptr);

	if (*endptr != '\0' || endptr == c)
	{
		return false;
	}
	return true;
}

Vector<double> Parser::parseNumbers(string numbersStr)
{
	istringstream iss(numbersStr);
	Vector<string> components = splitToWords(&iss, ' ');

	Vector<double> result;
	for (int i = 0; i < components.length(); i++)
	{
		//Проверяваме дали векторът се състои само от числа
		if (is_number(components[i]))
		{
			result.push_back(stod(components[i]));
		}

		else if (components[i] == "\n")
		{
			return result;
		}

		else
		{
			cout << "A not valid digit occurred." << endl;
			exit(1);
		}
	}

	return result;
}

