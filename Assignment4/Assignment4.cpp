// Assignment4.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "Store.h"

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
	Store store;

	ifstream moviesFile("data4movies.txt");
	if (!moviesFile)
	{
		cout << "Movie file not found." << endl;
		return -1;
	}

	ifstream customersFile("data4customers.txt");
	if (!customersFile)
	{
		cout << "Customers file not found." << endl;
		return -1;
	}

	ifstream commandsFile("data4commands.txt");
	if (!commandsFile)
	{
		cout << "Command file not found." << endl;
		return -1;
	}

	store.readMovies(moviesFile);
	store.readCustomers(customersFile);
	store.readCommands(commandsFile);

    return 0;
}

