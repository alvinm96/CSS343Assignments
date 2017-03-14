/*
	The Transaction class acts as the superclass for the Borrow and Return classes.
	The Transaction class takes in the id of the customer making the transaction.
*/
#pragma once
#include "BSTree.h"
#include "HashTable.h"
#include "Movie.h"
#include "Classic.h"
#include "Comedy.h"
#include "Drama.h"

#include <sstream>

using namespace std;

class Transaction
{
public:
	Transaction();
	virtual ~Transaction();

	virtual void processTrans(string line, BSTree &movie, HashTable &customer);

private:
	int customerId;
	char mediaType;
	char movieType;	
};

