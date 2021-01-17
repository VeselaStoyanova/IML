#pragma once
#include "Tag.h"
#include "Stack.h"
#include "Operation.h"
#include <string>
#include <sstream>
#include <algorithm>
#include <stdlib.h>

using namespace std;

class Parser
{
public:
	Vector<double> parseContent(string content);

private:
	Vector<double> evaluateContent(Vector<string> tags);
	Operation parseClosingOperation(string operAndArgum);
	Operation parseOperation(string operAndArgum);
	string parseArgument(string operAndArgum, Operation operation);
	Vector<double> parseNumbers(string numbersStr);
};