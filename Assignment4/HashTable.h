// TODO: Improve hash function, resize table, same id check

#pragma once
#include "HashedCustomer.h"

class HashTable
{
public:
	HashTable();
	~HashTable();

	bool addCustomer(int id, string name);
	bool removeCustomer(int id);
	HashedCustomer* getCustomer(int id);

private:
	int itemCount;
	int hashTableSize;
	static const int DEFAULT_SIZE = 101;
	HashedCustomer* hashTable[DEFAULT_SIZE];

	int getHashIndex(int id); // Hash function
};

