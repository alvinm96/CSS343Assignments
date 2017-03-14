/*
	The Borrow class is a subclass of Transaction. This allows a Customer to 
	borrow a movie they want. Once borrowed, the stock count of the movie decreases.
*/
#pragma once
#include "Transaction.h"

class Borrow: public Transaction
{
public:
	Borrow();
	~Borrow();

	virtual void processTrans(string line, BSTree &movieTree, HashTable &customerTable);
};

