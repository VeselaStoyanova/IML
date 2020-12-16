#include "Stack.h"
#include "Tag.h"

void testStack()
{
	Stack<char> firstStack;
	firstStack.push('c');
	firstStack.push('b');
	firstStack.push('a');
	firstStack.printStack();
	firstStack.pop();
	firstStack.pop();
	firstStack.pop();
	firstStack.printStack();
}

void testClassTag()
{
	Tag firstTag = Tag();
	Tag secondTag = Tag(Operation::AGG_AVG, "a12", { 1.1, 1.2, 1.3 });
	cout << secondTag;

	Tag thirdTag = secondTag;
	cout << thirdTag;

	Tag fourthTag = Tag(secondTag);
	cout << fourthTag;
}

void printVector(vector<double> vector)
{
	for (int i = 0; i < vector.size(); i++)
	{
		cout << vector[i] << " ";
	}
	cout << endl;
}

void testFunctions()
{
	double number = 4;
	string firstArgument = "ASC";
	string secondArgument = "DSC";

	vector<double> numbers = { 1.0, 1.0, 3.0, 4.0, 5.0 };
	printVector(numbers);
	cout << endl;

	Tag firstTag = Tag(Operation:: MAP_INC, "2", numbers);
	vector<double> resultMapInc = firstTag.mapInc();
	cout << "MAP-INC: " << endl;
	printVector(resultMapInc);
	cout << endl;

	Tag secondTag = Tag(Operation::MAP_MLT, "2", numbers);
	vector<double> resultMapMlt = secondTag.mapMlt();
	cout << "MAP-MLT: " << endl;
	printVector(resultMapMlt);

	Tag thirdTag = Tag(Operation::AGG_SUM, numbers);
	vector<double> resultAggSum = thirdTag.aggSum();
	cout << "AGG-SUM: " << endl;
	printVector(resultAggSum);

	Tag fourthTag = Tag(Operation::AGG_PRO, numbers);
	vector<double> resultAggPro = fourthTag.aggPro();
	cout << "AGG-PRO: " << endl;
	printVector(resultAggPro);

	Tag fifthTag = Tag(Operation::AGG_AVG, numbers);
	vector<double> resultAggAvg = fifthTag.aggAvg();
	cout << "AGG-AVG: " << endl;
	printVector(resultAggAvg);

	Tag sixthTag = Tag(Operation::AGG_FST, numbers);
	vector<double> resultAggFst = sixthTag.aggFst();
	cout << "AGG-FST: " << endl;
	printVector(resultAggFst);

	Tag seventhTag = Tag(Operation::AGG_LST, numbers);
	vector<double> resultAggLst = seventhTag.aggLst();
	cout << "AGG-LST: " << endl;
	printVector(resultAggLst);

	Tag eightTag = Tag(Operation::SRT_REV, numbers);
	vector<double> resultSrtRev = eightTag.srtRev();
	cout << "SRT-REV: " << endl;
	printVector(resultSrtRev);

	Tag ninthTag = Tag(Operation::SRT_ORD, firstArgument, numbers);
	vector<double> resultSrtOrdAsc = ninthTag.srtOrd();
	cout << "SRT-ORD ASC: " << endl;
	printVector(resultSrtOrdAsc);


	Tag tenthTag = Tag(Operation::SRT_ORD, secondArgument, numbers);
	vector<double> resultSrtOrdDsc = tenthTag.srtOrd();
	cout << "SRT-ORD DSC: " << endl;
	printVector(resultSrtOrdDsc);

	Tag eleventhTag = Tag(Operation::SRT_SLC, "2", numbers);
	vector<double>resultSrtSlc = eleventhTag.srtSlc();
	cout << "SRT-SLC: " << endl;
	printVector(resultSrtSlc);

	Tag twelfthTag = Tag(Operation::SRT_DST, numbers);
	vector<double>resultSrtDst = twelfthTag.srtDst();
	cout << "SRT-DST: " << endl;
	printVector(resultSrtDst);
}

int main()
{
	//testStack();
	//testClassTag();
	//testFunctions();
	Tag firstTag = Tag(Operation::MAP_INC, "1", { 1.0, 2.0, 3.0 });
	Tag secondTag = Tag(Operation::AGG_SUM, "1", { 1.0, 2.0, 3.0 });
	Tag thirdTag = Tag(Operation::SRT_ORD, "DSC", { 4.0, 2.0, 3.0 });
	//printVector(firstTag.calculate());
	//printVector(secondTag.calculate());
	printVector(thirdTag.calculate());
	return 0;
}

