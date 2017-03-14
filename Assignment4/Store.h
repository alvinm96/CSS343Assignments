/*
	The Store class holds a binary search tree of the inventory, a hash table 
	of customers, a history of transactions, and the store name. This class also
	handles the text files provided for the assignment. This class also allows 
	user to show inventory and show the history of a customer.
*/
#pragma once
#include <iostream>
#include <fstream>

#include "BSTree.h"
#include "HashTable.h"
#include "MovieFactory.h"
#include "Movie.h"
#include "Drama.h"
#include "Comedy.h"
#include "Classic.h"

#include "TransactionFactory.h"
#include "Transaction.h"
#include "Borrow.h"
#include "Return.h"

using namespace std;

class Store
{
public:
	Store();
	~Store();

	void readCommands(ifstream &file); // Read in data4commands for testing
	void readCustomers(ifstream &file); // Read in data4customers for adding customers
	void readMovies(ifstream &file); // Read in data4movies for adding movies

	void inventory();
private:
	BSTree dramaTree, comedyTree, classicTree; // Trees for each type of movie
	HashTable customerTable;
};

