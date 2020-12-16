#pragma once
#include "Operation.h"
using namespace std;

#include <vector>

class Tag
{
private:
	Operation operation;
	string argument;
	vector<double> numbers;
	void copy(const Tag& other);

public:
	Tag();
	Tag(Operation operation, string argument, vector<double> number);
	Tag(Operation operation, vector<double> numbers);
	Tag(const Tag& other);
	Tag& operator=(const Tag& other);
	bool operator==(const Tag& other);

	friend ostream& operator<<(ostream& output, const Tag& tag);
	void sortDsc(vector<double>& vector);
	void bubbleSort(vector<double>& vector);
	void remove();

	vector<double> aggSum();
	vector<double> aggPro();
	vector<double> aggAvg();
	vector<double> aggFst();
	vector<double> aggLst();

	vector<double> mapInc();
	vector<double> mapMlt();

	vector<double> srtRev();
	vector<double> srtOrd();
	vector<double> srtSlc();
	vector<double> srtDst();

	vector<double> calculate();
};

