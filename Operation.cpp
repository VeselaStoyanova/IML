#include <iostream>
#include <unordered_map>
#include "Operation.h"
using namespace std;

Operation switchOperation(string operationName)
{
	auto pair = operationTable.find(operationName);

	if (pair != operationTable.end())
	{
		return pair->second;
	}

	else
	{
		cout << "Not a valid operation." << endl;
	}
}

bool isOperationValid(string operationName)
{
	auto pair = operationTable.find(operationName);
	return pair != operationTable.end();
}
