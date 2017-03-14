#pragma once
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Customer
{
public:
	Customer(int id, string name);
	~Customer();

	int getId() const;
	string getName() const;

	void setId(int id);
	void setName(string name);
	void addToHistory(string line);

	void printHistory();

private: 
	int id;
	string name;

	vector<string> history;

protected:
	Customer();
};

