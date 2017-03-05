/*
	The Return class is a subclass of Return. This allows a Customer to return 
	the movie they borrowed. Once returned, the stock count of the movie increases.
*/
#pragma once
#include "Transaction.h"

class Return: Transaction
{
public:
	Return();
	~Return();
};

