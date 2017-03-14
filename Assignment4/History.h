#pragma once
#include "Transaction.h"

class History: public Transaction
{
public:
	History();
	~History();

	virtual void processTrans(string line, BSTree &movieTree, HashTable &customerTable);
};

