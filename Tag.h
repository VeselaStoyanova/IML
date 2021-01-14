#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <cstdlib>
#include "Vector.h"
#include "Operation.h"
using namespace std;

class Tag
{
private:
	Operation operation;
	string argument;
	Vector<double> numbers;
	void copy(const Tag& other);

public:
	Tag();
	Tag(Operation operation, string argument, Vector<double> number);
	Tag(Operation operation, Vector<double> numbers);
	Tag(const Tag& other);
	Tag& operator=(const Tag& other);
	bool operator==(const Tag& other);

	Operation getOperation();

	friend ostream& operator<<(ostream& output, Tag& tag);
	friend istream& operator>>(istream& input, Tag& tag);

	void sortAsc(Vector<double>& vector);
	void sortDsc(Vector<double>& vector);
	bool hasDuplicatesInInterval(Vector<double> vec, int left, int right, double value);

	Vector<double> removeDuplicates();
	Vector<double> reverseVector(Vector<double> vector);

	Vector<double> map(bool isOperationIncrease);

	Vector<double> mapInc();
	Vector<double> mapMlt();
	
	Vector<double> agg(bool isOperationSum);
	Vector<double> aggSum();
	Vector<double> aggPro();
	Vector<double> aggAvg();

	Vector<double> aggEl(bool isOperationFst);
	Vector<double> aggFst();
	Vector<double> aggLst();
	
	Vector<double> srtRev();
	Vector<double> srtOrd();
	Vector<double> srtSlc();
	Vector<double> srtDst();

	Vector<double> calculate();
	
	void addNumbers(Vector<double> newNumbers);
};

