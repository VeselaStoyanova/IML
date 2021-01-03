#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>
#include <sstream>
#include "Tests.h"
#include "Tag.h"
#include "Parser.h"
using namespace std;

Vector<string> getFileNames()
{
	Vector<string> fileNames;
	string line;
	getline(cin, line);

	istringstream iss(line);
	string s;
	while (getline(iss, s, ' '))
	{
		fileNames.push_back(s.c_str());
	}

	if (fileNames.length() != 2)
	{
		cout << "Wrong user input." << endl;
	}

	for (auto it = fileNames.begin(); it != fileNames.end(); ++it)
	{
		cout << *it << " ";
	}

	return fileNames;
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

void getUserInput()
{
	ifstream fs;
	ofstream ft;
	string str;

	cout << "Enter Source File with Extension: ";
	Vector<string> fileNames = getFileNames();
	string sourcefile = fileNames[0];
	string destinationfile = fileNames[1];

	fs.open(sourcefile);
	if (!fs)
	{
		cout << "Error in opening source file...!!!";
		exit(1);
	}

	ft.open(destinationfile);
	if (!ft)
	{
		cout << "Error in opening destination file...!!!";
		exit(2);
	}

	if (fs && ft)
	{
		stringstream buffer;
		buffer << fs.rdbuf();
		Parser p;
		Vector<double> result = p.parseContent(buffer.str());

		for (int i = 0; i < result.length(); i++)
		{
			ft << result[i] << " ";
		}

		cout << "Source file date successfully copied to destination file!!!";
	}

	else
	{
		cout << "File cannot open...!!!";
	}

	cout << endl << "Open destination file and check!!!";
	fs.close();
	ft.close();
}

int main()
{
	//testTags();
	getUserInput();

	return 0;
}

