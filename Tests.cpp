#include "Tests.h"

double number = 4;
string firstArgument = "ASC";
string secondArgument = "DSC";

Vector<double> createNumbers() 
{
	Vector<double> numbers;
	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);
	return numbers;
}

Vector<double> numbers = createNumbers();

void testClassStack()
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
	Stack<double> secondStack;
	secondStack.push(1.1);
	secondStack.push(3.4);
	secondStack.push(12.3);
	secondStack.pop();
	secondStack.push(1);
	secondStack.push(3.1);
	secondStack.pop();
	secondStack.printStack();
}

void testClassTag()
{
	Vector<double> firstVector;
	firstVector.push_back(1);
	firstVector.push_back(2);
	firstVector.push_back(3);
	Tag firstTag = Tag();
	Tag secondTag = Tag(Operation::MAP_INC, "1",firstVector);
	cout << secondTag;

	Tag thirdTag = secondTag;
	cout << thirdTag;

	Tag fourthTag = Tag(secondTag);
	cout << fourthTag;
}

void printVector(Vector<double> vector)
{
	for (int i = 0; i < vector.length(); i++)
	{
		cout << vector[i] << " ";
	}
	cout << endl;
}

void testMapInc()
{
	Tag firstTag = Tag(Operation::MAP_INC, "2", numbers);
	Vector<double> resultMapInc = firstTag.mapInc();
	cout << "MAP-INC: " << endl;
	printVector(resultMapInc);
}

void testMapMlt()
{
	Tag secondTag = Tag(Operation::MAP_MLT, "2", numbers);
	Vector<double> resultMapMlt = secondTag.mapMlt();
	cout << "MAP-MLT: " << endl;
	printVector(resultMapMlt);
}

void testAggSum()
{
	Tag thirdTag = Tag(Operation::AGG_SUM, numbers);
	Vector<double> resultAggSum = thirdTag.aggSum();
	cout << "AGG-SUM: " << endl;
	printVector(resultAggSum);
}

void testAggPro()
{
	Tag fourthTag = Tag(Operation::AGG_PRO, numbers);
	Vector<double> resultAggPro = fourthTag.aggPro();
	cout << "AGG-PRO: " << endl;
	printVector(resultAggPro);
}

void testAggAvg()
{
	Tag fifthTag = Tag(Operation::AGG_AVG, numbers);
	Vector<double> resultAggAvg = fifthTag.aggAvg();
	cout << "AGG-AVG: " << endl;
	printVector(resultAggAvg);
}

void testAggFst()
{
	Tag sixthTag = Tag(Operation::AGG_FST, numbers);
	Vector<double> resultAggFst = sixthTag.aggFst();
	cout << "AGG-FST: " << endl;
	printVector(resultAggFst);
}

void testAggLst()
{
	Tag seventhTag = Tag(Operation::AGG_LST, numbers);
	Vector<double> resultAggLst = seventhTag.aggLst();
	cout << "AGG-LST: " << endl;
	printVector(resultAggLst);
}

void testSrtRev()
{
	Tag eighthTag = Tag(Operation::SRT_REV, numbers);
	Vector<double> resultSrtRev = eighthTag.srtRev();
	cout << "SRT-REV: " << endl;
	printVector(resultSrtRev);
}

void testSrtOrdAsc()
{
	Tag ninthTag = Tag(Operation::SRT_ORD, firstArgument, numbers);
	Vector<double> resultSrtOrdAsc = ninthTag.srtOrd();
	cout << "SRT-ORD ASC: " << endl;
	printVector(resultSrtOrdAsc);
}

void testSrtOrdDsc()
{
	Tag tenthTag = Tag(Operation::SRT_ORD, secondArgument, numbers);
	Vector<double> resultSrtOrdDsc = tenthTag.srtOrd();
	cout << "SRT-ORD DSC: " << endl;
	printVector(resultSrtOrdDsc);
}

void testSrtSlc()
{
	Tag eleventhTag = Tag(Operation::SRT_SLC, "2", numbers);
	Vector<double>resultSrtSlc = eleventhTag.srtSlc();
	cout << "SRT-SLC: " << endl;
	printVector(resultSrtSlc);
}

void testSrtDst()
{
	Tag twelfthTag = Tag(Operation::SRT_DST, numbers);
	Vector<double>resultSrtDst = twelfthTag.srtDst();
	cout << "SRT-DST: " << endl;
	printVector(resultSrtDst);
}

void testTags()
{
	//testClassStack();
	//testClassTag();
	//testMapInc();
	//testMapMlt();
	//testAggSum();
	//testAggPro();
	//testAggAvg();
	//testAggFst();
	//testAggLst();
	//testSrtRev();
	//testSrtOrdAsc();
	//testSrtOrdDsc();
	//testSrtSlc();
	//testSrtDst();

	Vector<double> firstVector;
	firstVector.push_back(1);
	firstVector.push_back(2);
	firstVector.push_back(3);

	Tag firstTag = Tag(Operation::MAP_INC, "1", firstVector);
	Tag secondTag = Tag(Operation::AGG_AVG, firstVector);
	Tag thirdTag = Tag(Operation::SRT_ORD, "DSC", firstVector);
	Tag fourthTag = Tag(Operation::SRT_REV, firstVector);
	Tag fifthTag = Tag(Operation::SRT_SLC, "3", firstVector);
	Tag sixthTag = Tag(Operation::SRT_DST, firstVector);
	Tag seventhTag = Tag(Operation::SRT_ORD, "ASC", firstVector);

	//printVector(firstTag.calculate());
	//printVector(secondTag.calculate());
	//printVector(thirdTag.calculate());
	//printVector(fourthTag.calculate());
	//printVector(fifthTag.calculate());
	//printVector(sixthTag.calculate());
	//printVector(seventhTag.calculate());
	//firstTag.saveFile("newFile.txt");
}
