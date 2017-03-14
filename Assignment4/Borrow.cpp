#include "stdafx.h"
#include "Borrow.h"

Borrow::Borrow()
{
}

Borrow::~Borrow()
{
}

//-------------------------processTrans----------------------------------------
// Precondition: line is in the correct format
// Process the borrow transaction. 
//-----------------------------------------------------------------------------
void Borrow::processTrans(string line, BSTree &movieTree, HashTable &customerTable)
{
	istringstream iss(line);
	string transType, id, mediaType, movieType;
	iss >> transType >> id >> mediaType >> movieType;

	// Check if customer exists, return if DNE
	HashedCustomer* customer = customerTable.getCustomer(stoi(id));
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
	if (movieType == "C")
	{
		// Parse month and year from line
		int month, year;

		iss >> month >> year;

		string actorFirstName, actorLastName;
		iss >> actorFirstName >> actorLastName;

		temp = new Classic("", "", month, year);

		static_cast<Classic *>(temp)->addActor(actorFirstName + " " + actorLastName);
	}
	else if (movieType == "F")
	{
		string title = line.substr(10, (line.find(',') - 10));
		int year = stoi(line.substr((line.find(',') + 1) , 5));
		temp = new Comedy(title, year);
	}
	else if (movieType == "D")
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
		found->subtractStock(1);
	}
}