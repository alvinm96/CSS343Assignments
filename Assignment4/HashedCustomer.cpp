#include "stdafx.h"
#include "HashedCustomer.h"

HashedCustomer::HashedCustomer(int id, string name)
{
	setId(id);
	setName(name);
}


HashedCustomer::~HashedCustomer()
{
}

void HashedCustomer::setNext(HashedCustomer *next)
{
	this->nextPtr = next;
}

HashedCustomer* HashedCustomer::getNext() const
{
	return this->nextPtr;
}

HashedCustomer::HashedCustomer() { }
