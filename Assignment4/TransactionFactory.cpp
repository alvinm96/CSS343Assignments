#include "stdafx.h"
#include "TransactionFactory.h"

Transaction* TransactionFactory::makeTrans(char type)
{
	Transaction *trans;
	if (type == 'B')
	{
		trans = new Borrow();
	}
	else if (type == 'R')
	{
		trans = new Return();
	}
	else if (type == 'H')
	{
		trans = new History();
	}
	else if (type == 'I')
	{
		trans = NULL;
	}
	else
	{
		cout << "[TRANSACTION ERROR] Transaction does not exist" << endl;
		trans = NULL;
	}
	return trans;
}
