#include "stdafx.h"
#include "History.h"


History::History()
{
}


History::~History()
{
}

void History::processTrans(string line, BSTree &movieTree, HashTable &customerTable)
{
	int id = stoi(line.substr(2, 5)); // Customer id from the line
	HashedCustomer* customer = customerTable.getCustomer(id);
	if (customer == NULL)
	{
		cout << "[TRANSACTION ERROR] Customer does not exist" << endl;
		return;
	}
	else
	{
		customer->printHistory(); // Print history
	}
}
