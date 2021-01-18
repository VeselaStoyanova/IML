#include "Tag.h"

void Tag::copy(const Tag& other)
{
	this->operation = other.operation;
	this->argument = other.argument;
	this->numbers = other.numbers;
}

Tag::Tag()
{
	this->operation = Operation();
	this->argument = "";
	this->numbers = {};
}

Tag::Tag(Operation operation, string argument, Vector<double>numbers)
{
	this->operation = operation;
	this->argument = argument;
	this->numbers = numbers;
}

Tag::Tag(Operation operation, Vector<double> numbers)
{
	this->operation = operation;
	this->numbers = numbers;
}

Tag::Tag(const Tag& other)
{
	this->copy(other);
	this->operation = other.operation;
	this->argument = other.argument;
	this->numbers = other.numbers;
}

Tag& Tag::operator=(const Tag& other)
{
	if (this != &other)
	{
		this->copy(other);
	}

	return *this;
}

bool Tag::operator==(const Tag& other)
{
	return this->operation == other.operation &&
		this->argument == other.argument &&
		this->numbers == other.numbers;
}

Operation Tag::getOperation()
{
	return operation;
}

ostream& operator<<(ostream& output, Tag& tag)
{
	output << tag.operation << endl;
	output << tag.argument << endl;
	for (int i = 0; i < tag.numbers.length(); i++)
	{
		output << tag.numbers[i] << " ";
	}
	cout << endl;

	return output;
}

istream& operator>>(istream& input, Tag& tag)
{
	while (input && !input.eof())
	{
		char el = input.peek();
	}
	return input;
}

//функция, която сортира вектора в нарастващ ред
void Tag::sortAsc(Vector<double>& vec)
{
	bool swapped = true;
	while (swapped == true)
	{
		swapped = false;
		for (int i = 0; i < vec.length() - 1; i++) 
		{
			for (int j = i + 1; j < vec.length(); j++)
			{
				if (vec[i] > vec[j])
				{
					vec.swapValues(i,j);
					swapped = true;
				}
			}
		}
	}
}

//функция, която сортира вектора в намаляващ ред
void Tag::sortDsc(Vector<double>& vector)
{
	for (int i = 0; i < vector.length() - 1; i++) 
	{
		for (int j = i + 1; j < vector.length(); j++)
		{
			if (vector[j] > vector[i])
			{
				vector.swapValues(j,i);
			}
		}
	}
}

Vector<double> Tag::map(bool isOperationIncrease)
{
	Vector<double> result;
	double number = stod(this->argument);

	for (int i = 0; i < numbers.length(); i++)
	{
		double newElement;
		if (isOperationIncrease)
		{
			newElement = numbers[i] + number;
		}

		else
		{
			newElement = numbers[i] * number;
		}

		result.push_back(newElement);
	}

	return result;
}

//функция, която добавя елемент към всеки елемент от вектора
Vector<double> Tag::mapInc()
{
	return map(true);
}

//функция, която умножава всеки елемент от вектора с друг
Vector<double> Tag::mapMlt()
{
	return map(false);
}

Vector<double> Tag::agg(bool isOperationSum)
{
	Vector<double> sums;
	double result;

	if (isOperationSum)
	{
		result = 0;
	}

	else
	{
		result = 1;
	}

	for (int i = 0; i < numbers.length(); i++)
	{

		if (isOperationSum)
		{
			result = result + numbers[i];
		}

		else
		{
			result = result * numbers[i];
		}
	
	}
	sums.push_back(result);
	return sums;
}

//функция, която намира сумата на елементите във вектора
Vector<double> Tag::aggSum()
{
	return agg(true);
}

//функция, която намира произведението на елементите във вектора
Vector<double> Tag::aggPro()
{
	return agg(false);
}

//функция, която намира средно-аритметичното на елементите във вектора
Vector<double> Tag::aggAvg()
{
	Vector<double> result;
	Vector<double> sums = aggSum();
	double agg = 0;

	for (int i = 0; i < sums.length(); i++)
	{
		agg =  sums[i]/ numbers.length();
	}

	result.push_back(agg);
	return result;
}

Vector<double> Tag::aggEl(bool isOperationFst)
{
	Vector<double> result;
	if (isOperationFst)
	{
		result.push_back(numbers.first());
	}

	else
	{
		result.push_back(numbers.last());
	}
	return result;
}

//функция, която намира първия елемент във вектора
Vector<double> Tag::aggFst()
{
	return aggEl(true);
}

//функция, която намира последния елемент във вектора
Vector<double> Tag::aggLst()
{
	return aggEl(false);
}

Vector<double> Tag::reverseVector(Vector<double> vec)
{
	for (int i = 0; i < vec.length()/2; i++)
	{
		vec.swapValues(i, vec.length() - i - 1);
	}

	return vec;
}

//функция, която обръща вектора
Vector<double> Tag::srtRev()
{
	Vector<double> result;

	for (int i = 0; i < numbers.length(); i++)
	{
		result.push_back(numbers[i]);
	}

	Vector<double> vec1 = reverseVector(result);

	return vec1;
}

//функция, която сортира вектора
Vector<double> Tag::srtOrd()
{
	Vector<double> result;

	for (int i = 0; i < numbers.length(); i++)
	{
		result.push_back(numbers[i]);
	}

	//сортира вектора във възходящ ред
	if (this->argument == "ASC")
	{
		sortAsc(result);
	}

	//сортира в низходящ ред
	else if(this->argument == "DSC")
	{
		sortDsc(result);
	}

	return result;
}

//функция, която връща подсписък от посочения индекс нататък
Vector<double> Tag::srtSlc()
{
	Vector<double> result;
	double number = stod(this->argument);
	for (int i = number; i < numbers.length(); i++)
	{
		result.push_back(numbers[i]);
	}

	return result;
}

bool Tag::hasDuplicatesInInterval(Vector<double> vec, int left, int right, double value)
{
	for (int i = left; i <= right; i++)
	{
		if (vec[i] == value)
		{
			return true;
		}
	}
	return false;
}

Vector<double> Tag::removeDuplicates()
{
	Vector<double> result;

	for (int i = 0; i < numbers.length(); i++)
	{
		if (!hasDuplicatesInInterval(numbers, 0, i - 1, numbers[i]))
		{
			result.push_back(numbers[i]);
		}
	}

	return result;

}

//функция, която премахва дубликати
Vector<double> Tag::srtDst()
{
	Vector<double> res = removeDuplicates();

	return res;
}

//функция, която от подадена операция връща съответната функция
Vector<double> Tag::calculate()
{
	switch(this->operation)
	{
	case Operation::MAP_INC: return mapInc();
		break;
	case Operation::MAP_MLT: return mapMlt();
		break;
	case Operation::AGG_SUM: return aggSum();
		break;
	case Operation::AGG_PRO: return aggPro();
		break;
	case Operation::AGG_AVG: return aggAvg();
		break;
	case Operation::AGG_FST: return aggFst();
		break;
	case Operation::AGG_LST: return aggLst();
		break;
	case Operation::SRT_REV: return srtRev();
		break;
	case Operation::SRT_ORD: return srtOrd();
		break;
	case Operation::SRT_SLC: return srtSlc();
		break;
	case Operation::SRT_DST: return srtDst();
		break;
	default: cout << "Invalid input";
		break;
	}
}

void Tag::addNumbers(Vector<double> newNumbers)
{
	for (int i = 0; i < newNumbers.length(); i++)
	{
		this->numbers.push_back(newNumbers[i]);
	}
}