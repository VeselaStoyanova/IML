#include<iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <cstdlib>
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

//функция, която добавя елемент към всеки елемент от вектора
Vector<double> Tag::mapInc()
{
	Vector<double> result;
	double number = stod(this->argument); 

	for (int i = 0; i < numbers.length(); i++)
	{
		result.push_back(numbers[i] + number);
	}

	return result;
}

//функция, която умножава всеки елемент от вектора с друг
Vector<double> Tag::mapMlt()
{
	Vector<double> result;
	double number = stod(this->argument);

	for (int i = 0; i < numbers.length(); i++)
	{
		result.push_back(numbers[i] * number);
	}

	return result;
}

//функция, която намира сумата на елементите във вектора
Vector<double> Tag::aggSum()
{
	Vector<double> sums;
	double sum = 0;

	for (int i = 0; i < numbers.length(); i++)
	{
		sum = sum + numbers[i];
	}

	sums.push_back(sum);
	return sums;
}

//функция, която намира произведението на елементите във вектора
Vector<double> Tag::aggPro()
{
	Vector<double> pros;
	double pro = 1;

	for (int i = 0; i < numbers.length(); i++)
	{
		pro = pro * numbers[i];
	}

	pros.push_back(pro);
	return pros;
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

//функция, която намира първия елемент във вектора
Vector<double> Tag::aggFst()
{
	Vector<double> result;
	result.push_back(*numbers.begin());
	return result;
}

//функция, която намира последния елемент във вектора
Vector<double> Tag::aggLst()
{
	Vector<double> result;
	result.push_back(*numbers.end());
	return result;
}

//функция, която обръща вектора
Vector<double> Tag::srtRev()
{
	Vector<double> result;
	//reverse(numbers.begin(), numbers.end());

	for (int i = 0; i < numbers.length(); i++)
	{
		result.push_back(numbers[i]);
	}

	return result;
}

//функция, която сортира вектора
Vector<double> Tag::srtOrd()
{
	Vector<double> result;

	//сортира вектора във възходящ ред
	if (this->argument == "ASC")
	{
		Vector<double> result;
		
		for (int i = 0; i < numbers.length(); i++)
		{
			result.push_back(numbers[i]);
		}
		sortAsc(result);
		return result;	
	}

	//сортира в низходящ ред
	else if(this->argument == "DSC")
	{
		Vector<double> result;

		for (int i = 0; i < numbers.length(); i++)
		{
			result.push_back(numbers[i]);
		}
		sortDsc(result);
		return result;
	}
}

//функция, която връща подсписък от посочения индекс нататък
Vector<double> Tag::srtSlc()
{
	Vector<double> result;
	double number = stoi(this->argument);
	for (int i = number; i < numbers.length(); i++)
	{
		result.push_back(numbers[i]);
	}

	return result;
}

void Tag::remove()
{
	auto end = numbers.end();

	for (auto it = numbers.begin(); it != end; ++it)
	{
		//end = std::remove(it + 1, end, *it);
	}

	//numbers.erase(end, numbers.end());
}

//функция, която премахва дубликати
Vector<double> Tag::srtDst()
{
	Vector<double> result;
	remove();

	for (auto it = numbers.begin(); it != numbers.end(); ++it)
	{
		result.push_back(*it);
	}

	return result;
}

//функция, която от подадена операция връща съответната функция
Vector<double> Tag::calculate()
{
	switch(this->operation)
	{
	case MAP_INC: return mapInc();
		break;
	case MAP_MLT: return mapMlt();
		break;
	case AGG_SUM: return aggSum();
		break;
	case AGG_PRO: return aggPro();
		break;
	case AGG_AVG: return aggAvg();
		break;
	case AGG_FST: return aggFst();
		break;
	case AGG_LST: return aggLst();
		break;
	case SRT_REV: return srtRev();
		break;
	case SRT_ORD: return srtOrd();
		break;
	case SRT_SLC: return srtSlc();
		break;
	case SRT_DST: return srtDst();
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