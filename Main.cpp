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

	return fileNames;
}

void getUserInput()
{
	ifstream fs;
	ofstream ft;
	string str;

	cout << "Enter Source File and Destination File with Extensions: ";
	Vector<string> fileNames = getFileNames();
	string sourcefile = fileNames[0];
	string destinationfile = fileNames[1];

	fs.open(sourcefile);
	if (!fs)
	{
		cout << "Error in opening source file...!!!" << endl;
		exit(1);
	}

	ft.open(destinationfile);
	if (!ft)
	{
		cout << "Error in opening destination file...!!!" << endl;
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
		
		cout << endl;
		cout << "Source file date successfully copied to destination file!!!" << endl;
	}

	else
	{
		cout << "File cannot open...!!!" << endl;
	}

	cout << endl << "Open destination file and check!!!" << endl;
	fs.close();
	ft.close();
}

int main()
{
	getUserInput();

	return 0;
}

