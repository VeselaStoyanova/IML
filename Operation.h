#pragma once
#include <iostream>
#include <unordered_map>
using namespace std;

enum Operation
{
	MAP_INC,
	MAP_MLT,
	AGG_SUM,
	AGG_PRO,
	AGG_AVG,
	AGG_FST,
	AGG_LST,
	SRT_REV,
	SRT_ORD,
	SRT_SLC,
	SRT_DST
};	   

static unordered_map<string, Operation> const operationTable =
{
	{"MAP-INC", Operation::MAP_INC},
	{"MAP-MLT", Operation::MAP_MLT},
	{"AGG-SUM", Operation::AGG_SUM},
	{"AGG-PRO", Operation::AGG_PRO},
	{"AGG-AVG", Operation::AGG_AVG},
	{"AGG-FST", Operation::AGG_FST},
	{"AGG-LST", Operation::AGG_LST},
	{"SRT-REV", Operation::SRT_REV},
	{"SRT-ORD", Operation::SRT_ORD},
	{"SRT-SLC", Operation::SRT_SLC},
	{"SRT-DST", Operation::SRT_DST}
};

Operation switchOperation(string operationName);
bool isOperationValid(string operationName);