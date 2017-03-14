#include "stdafx.h"
#include "Customer.h"

Customer::Customer() { }

Customer::Customer(int id, string name)
{
	setId(id);
	setName(name);
}

Customer::~Customer()
{
}

int Customer::getId() const
{
	return id;
}

string Customer::getName() const
{
	return name;
}

void Customer::setId(int id)
{
	this->id = id;
}

void Customer::setName(string name)
{
	this->name = name;
}

void Customer::addToHistory(string line)
{
	history.push_back(line);
}

void Customer::printHistory()
{
	cout << "History for " << this->getName() << endl;
	for (int i = 0; i < history.size(); i++)
	{
		cout << history[i] << endl;
	}
}
