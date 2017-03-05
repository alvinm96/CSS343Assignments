/*
	The Transaction class acts as the superclass for the Borrow and Return classes.
	The Transaction class takes in the id of the customer making the transaction.
*/
#pragma once
class Transaction
{
public:
	Transaction();
	virtual ~Transaction();

//	virtual void processTrans();

private:
	int customerId;
	char mediaType;
	char movieType;
};

