#include "Parser.h"

Vector<double> Parser::parseContent(string content)
{
	istringstream iss(content);
	Vector<string> tagRows;
	string s;

	while (getline(iss, s, '<')) 
	{
		tagRows.push_back(s.c_str());
	}

	tagRows.pop_front();			//Първият елемент е празен стринг и го изтриваме.
	Vector<double> result = evaluateContent(tagRows);
	return result;
}

Vector<double> Parser::evaluateContent(Vector<string> tagRows)
{
	Stack<Tag> tags;
	Vector<double> result;

	for (auto it = tagRows.begin(); it != tagRows.end(); ++it) 
	{
		istringstream iss(*it);
		Vector<string> components;
		string s;
		while (getline(iss, s, '>'))
		{
			components.push_back(s.c_str());
		}

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
			Tag lastTag = tags.top();
			result = lastTag.calculate();
			tags.pop();
			if (!tags.empty())
			{
				Tag newLastTag = tags.top();
				tags.pop();
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

	return result;
}

Operation Parser::parseClosingOperation(string operAndArgum)
{
	istringstream iss(operAndArgum.substr(1));
	Vector<string> components;
	string s;
	while (getline(iss, s, ' '))
	{
		components.push_back(s.c_str());
	}

	return switchOperation(components[0]);
}

Operation Parser::parseOperation(string operAndArgum)
{
	istringstream iss(operAndArgum);
	Vector<string> components;
	string s;
	while (getline(iss, s, ' ')) 
	{
		components.push_back(s.c_str());
	}

	return switchOperation(components[0]);
}

string Parser::parseArgument(string operAndArgum, Operation operation)
{
	bool needsArgument = operation == MAP_INC || operation == MAP_MLT || operation == SRT_ORD || operation == SRT_SLC;

	istringstream iss(operAndArgum);
	Vector<string> components;
	string s;
	while (getline(iss, s, ' ')) 
	{
		components.push_back(s.c_str());
	}
	
	bool hasArgument = components.length() > 1;

	if (needsArgument && !hasArgument)
	{
		cout << "The required argument for the operation " << operation << " is missing." << endl;
	}

	if (!needsArgument && hasArgument)
	{
		cout << "There is a redundant argument for the operation " << operation << " . " << endl;
	}

	if (needsArgument && hasArgument)
	{
		string argument = components[1];
		argument.erase(remove(argument.begin(), argument.end(), '\"'), argument.end());
		return argument;
	}

	return "";
}

bool is_number(const std::string& s)
{
	std::string::const_iterator it = s.begin();
	while (it != s.end() && std::isdigit(*it)) ++it;
	return !s.empty() && it == s.end();
}

Vector<double> Parser::parseNumbers(string numbersStr)
{
	istringstream iss(numbersStr);
	Vector<string> components;
	string s;
	while (getline(iss, s, ' '))
	{
		components.push_back(s.c_str());
	}

	Vector<double> result;
	for (auto it = components.begin(); it != components.end(); ++it)
	{
		if (!is_number(*it))
		{
			cout << "A not valid digit occurred." << endl;
		}

		else
		{
			result.push_back(stoi(*it));
		}
	}

	return result;
}

