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
	{"MAP-INC", MAP_INC},
	{"MAP-MLT", MAP_MLT},
	{"AGG-SUM", AGG_SUM},
	{"AGG-PRO", AGG_PRO},
	{"AGG-AVG", AGG_AVG},
	{"AGG-FST", AGG_FST},
	{"AGG-LST", AGG_LST},
	{"SRT-REV", SRT_REV},
	{"SRT-ORD", SRT_ORD},
	{"SRT-SLC", SRT_SLC},
	{"SRT-DST", SRT_DST}
};

Operation switchOperation(string operationName);
bool isOperationValid(string operationName);