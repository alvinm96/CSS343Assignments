#include "stdafx.h"
#include "HashTable.h"


HashTable::HashTable()
{
	for (int i = 0; i < DEFAULT_SIZE; i++)
	{
		hashTable[i] = NULL;
	}
}


HashTable::~HashTable()
{
}

// TODO: Same id
bool HashTable::addCustomer(int id, string name)
{
	HashedCustomer *customerToAdd = new HashedCustomer(id, name);
	int itemHashIndex = getHashIndex(id); // Compute hashed index into array

	if (hashTable[itemHashIndex] == NULL)
	{
		hashTable[itemHashIndex] = customerToAdd;
	}
	else
	{
		customerToAdd->setNext(hashTable[itemHashIndex]);
		hashTable[itemHashIndex] = customerToAdd;
	}
	itemCount++;
	return true;
}

bool HashTable::removeCustomer(int id)
{
	bool found = false;
	int itemHashIndex = getHashIndex(id);

	if (hashTable[itemHashIndex] != NULL)
	{
		// first node
		if (id == hashTable[itemHashIndex]->getId())
		{
			HashedCustomer *ptrToRemove = hashTable[itemHashIndex];
			hashTable[itemHashIndex] = hashTable[itemHashIndex]->getNext();
			delete ptrToRemove;
			ptrToRemove = NULL;
			found = true;
		}
		else // search rest of chain
		{
			HashedCustomer* cur = hashTable[itemHashIndex]->getNext();
			while (cur != NULL && !found)
			{
				HashedCustomer *prev = hashTable[itemHashIndex];
				HashedCustomer *cur = prev->getNext();
				if (id == cur->getId())
				{
					prev->setNext(cur->getNext());
					delete cur;
					cur = NULL;
					found = true;
				}
				else
				{
					prev = cur;
					cur = cur->getNext();
				}
			}
		}
	}
	return found;
}

HashedCustomer* HashTable::getCustomer(int id)
{
	int itemHashIndex = getHashIndex(id);

	if (hashTable[itemHashIndex] != NULL)
	{
		// first node
		if (id == hashTable[itemHashIndex]->getId())
		{
			return hashTable[itemHashIndex];
		}
		else // search rest of chain
		{
			HashedCustomer* cur = hashTable[itemHashIndex]->getNext();
			while (cur != NULL)
			{
				if (id == cur->getId())
				{
					return cur;
				}
				else
				{
					cur = cur->getNext();
				}
			}
		}
	}
}

// TODO: Improve hash function
int HashTable::getHashIndex(int id)
{
	return id % 10;
}
