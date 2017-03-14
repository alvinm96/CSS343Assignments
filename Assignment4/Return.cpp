#include "stdafx.h"
#include "Return.h"


Return::Return()
{
}


Return::~Return()
{
}

//-------------------------processTrans----------------------------------------
// Precondition: line is in the correct format
// Process the return transaction. 
//-----------------------------------------------------------------------------
void Return::processTrans(string line, BSTree & movieTree, HashTable & customerTable)
{
	int id = stoi(line.substr(2, 5)); // Customer id from the line
	char mediaType = line[7]; // Media type 
	char movieType = line[9]; // Movie type

	// Check if customer exists, return if DNE
	HashedCustomer* customer = customerTable.getCustomer(id);
	if (customer == NULL)
	{
		cout << "[TRANSACTION ERROR] Customer does not exist" << endl;
		return;
	}
	else
	{
		customer->addToHistory(line); // Add line to customer history
	}

	Movie *temp; // Temp Movie for retrieval. To be deleted after function
	if (movieType == 'C')
	{
		// Parse month and year from line
		int month = line[11];
		int year = stoi(line.substr(13, 4));
		string majorActor;
		temp = new Classic("", "", month, year);
	}
	else if (movieType == 'F')
	{
		string title = line.substr(10, (line.find(',') - 10));
		int year = stoi(line.substr((line.find(',') + 1), 4));
		temp = new Comedy(title, year);
	}
	else if (movieType == 'D')
	{
		string director = line.substr(10, (line.find(',') - 10));
		string title = line.substr((line.find(',') + 1), (line.length() - 1 - (line.find(',') + 1)));
		temp = new Drama(title, director);
	}
	else
	{
		temp = NULL;
		return;
	}

	Movie *found = NULL;
	movieTree.retrieve(temp, found);
	// Movie was found in tree
	if (found != NULL)
	{
		found->addStock(1);
	}
}
