#pragma once
#include "Transaction.h"
#include "Borrow.h"
#include "Return.h"
#include "History.h"

class TransactionFactory
{
public:
	static Transaction* makeTrans(char type);
};

