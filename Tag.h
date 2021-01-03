#pragma once
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

	friend ostream& operator<<(ostream& output, Tag& tag);
	friend istream& operator>>(istream& input, Tag& tag);

	void sortAsc(Vector<double>& vector);
	void sortDsc(Vector<double>& vector);
	void remove();

	Vector<double> mapInc();
	Vector<double> mapMlt();
	
	Vector<double> aggSum();
	Vector<double> aggPro();
	Vector<double> aggAvg();
	Vector<double> aggFst();
	Vector<double> aggLst();
	
	Vector<double> srtRev();
	Vector<double> srtOrd();
	Vector<double> srtSlc();
	Vector<double> srtDst();

	Vector<double> calculate();
	
	void addNumbers(Vector<double> newNumbers);
};

