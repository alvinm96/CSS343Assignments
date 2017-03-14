#pragma once
#include "Customer.h"

class HashedCustomer: public Customer
{
public:
	HashedCustomer(int id, string name);
	~HashedCustomer();

	void setNext(HashedCustomer *next);
	HashedCustomer* getNext() const;

private:
	HashedCustomer *nextPtr;

protected:
	HashedCustomer();
};

