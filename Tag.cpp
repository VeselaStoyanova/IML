#include "Tag.h"
#include<iostream>
#include <vector>
#include <algorithm>
#include<string>

void Tag::copy(const Tag& other)
{
	this->operation = other.operation;
	this->argument = other.argument;
	this->numbers = other.numbers;
}

Tag::Tag()
{
	this->operation = Operation();
	this->argument = '\0';
	this->numbers = {};
}

Tag::Tag(Operation operation, string argument, vector<double>numbers)
{
	this->operation = operation;
	this->argument = argument;
	this->numbers = numbers;
}

Tag::Tag(Operation operation, vector<double> numbers)
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

ostream& operator<<(ostream& output, const Tag& tag)
{
	output << tag.operation << endl;
	output << tag.argument << endl;

	return output;
}

//функция, която сортира вектора в нарастващ ред
void Tag::bubbleSort(vector<double>& vector)
{
	bool swap = true;
	while (swap) {
		swap = false;
		for (size_t i = 0; i < vector.size() - 1; i++) {
			if (vector[i] > vector[i + 1]) {
				vector[i] += vector[i + 1];
				vector[i + 1] = vector[i] - vector[i + 1];
				vector[i] -= vector[i + 1];
				swap = true;
			}
		}
	}
}

//функция, която сортира вектора в намаляващ ред
void Tag::sortDsc(vector<double>& vector)
{
	for (int i = 0; i < vector.size(); i++) 
	{
		for (int j = i + 1; j < vector.size(); j++)
		{
			if (vector[j] > vector[i]) {
				swap(vector[j], vector[i]);
			}
		}
	}
}

//функция, която добавя елемент към всеки елемент от вектора
vector<double> Tag::mapInc()
{
	vector<double> result;
	double number = stod(this->argument);
	for (int i = 0; i < numbers.size(); i++)
	{
		result.push_back(numbers[i] + number);
	}

	return result;
}

//функция, която умножава всеки елемент от вектора с друг
vector<double> Tag::mapMlt()
{
	vector<double> result;
	double number = stod(this->argument);
	for (int i = 0; i < numbers.size(); i++)
	{
		result.push_back(numbers[i] * number);
	}

	return result;
}

//функция, която намира сумата на елементите във вектора
vector<double> Tag::aggSum()
{
	vector<double> sums;
	double sum = 0;

	for (int i = 0; i < numbers.size(); i++)
	{
		sum = sum + numbers[i];
	}

	sums.push_back(sum);
	return sums;
}

//функция, която намира произведението на елементите във вектора
vector<double> Tag::aggPro()
{
	vector<double> pros;
	double pro = 1;

	for (int i = 0; i < numbers.size(); i++)
	{
		pro = pro * numbers[i];
	}

	pros.push_back(pro);
	return pros;
}

//функция, която намира средно-аритметичното на елементите във вектора
vector<double> Tag::aggAvg()
{
	vector<double> result;
	vector<double> sums;
	double agg = 0;
	double sum = 0;

	for (int i = 0; i < numbers.size(); i++)
	{
		sum = sum + numbers[i];
	}

	sums.push_back(sum);

	for (int i = 0; i < sums.size(); i++)
	{
		agg = sum / numbers.size();
	}

	result.push_back(agg);
	return result;
}

//функция, която намира първия елемент във вектора
vector<double> Tag::aggFst()
{
	vector<double> result;
	result.push_back(numbers.front());
	return result;
}

//функция, която намира последния елемент във вектора
vector<double> Tag::aggLst()
{
	vector<double> result;
	result.push_back(numbers.back());
	return result;
}

//функция, която обръща вектора
vector<double> Tag::srtRev()
{
	vector<double> result;
	reverse(numbers.begin(), numbers.end());

	for (int i = 0; i < numbers.size(); i++)
	{
		result.push_back(numbers[i]);
	}

	return result;
}

//функция, която сортира вектора
vector<double> Tag::srtOrd()
{
	vector<double> result;

	//сортира вектора във възходящ ред
	if (this->argument == "ASC")
	{
		vector<double> result;
		
		for (int i = 0; i < numbers.size(); i++)
		{
			result.push_back(numbers[i]);
		}
		bubbleSort(result);
		return result;	
	}

	//сортира в низходящ ред
	else if(this->argument == "DSC")
	{
		vector<double> result;

		for (int i = 0; i < numbers.size(); i++)
		{
			result.push_back(numbers[i]);
		}
		sortDsc(result);
		return result;
	}
}

//функция, която връща подсписък от посочения индекс нататък
vector<double> Tag::srtSlc()
{
	vector<double> result;
	double number = stoi(this->argument);
	for (int i = number; i < numbers.size(); i++)
	{
		result.push_back(numbers[i]);
	}

	return result;
}

void Tag::remove()
{
	auto end = numbers.end();

	for (auto it = numbers.begin(); it != end; it++)
	{
		end = std::remove(it + 1, end, *it);
	}

	numbers.erase(end, numbers.end());
}

//функция, която премахва дупликати
vector<double> Tag::srtDst()
{
	vector<double> result;
	remove();

	for (auto it = numbers.cbegin(); it != numbers.cend(); it++)
	{
		result.push_back(*it);
	}
	return result;
}

//функция, която от подадена операция връща съответната функция
vector<double> Tag::calculate()
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