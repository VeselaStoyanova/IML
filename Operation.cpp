#include "Operation.h"
#include <unordered_map>
#include "Tag.h"
using namespace std;

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

Operation switchOperation(string operation)
{
	auto it = operationTable.find(operation);

	if (it != operationTable.end()) 
	{
		return it->second;
	}
	else
	{
		cout << "Not a valid operation.";
	}
}
