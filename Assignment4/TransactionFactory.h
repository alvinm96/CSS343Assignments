/*
	The TransactionFactory class uses a factory method approach for handling
	transactions.
*/
#pragma once
#include "Transaction.h"
#include <string>

using namespace std;

class TransactionFactory
{
public:
	TransactionFactory();
	~TransactionFactory();

	static Transaction* createTrans(string type);
};

