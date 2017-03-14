#include "stdafx.h"
#include "MovieFactory.h"

//--------------------makeMovie------------------------------------------------
//	Factory method for making movie object. This method takes in a string that 
//	has the title, director, movie type, release year of the movie. Classical 
//	movies will have a different format which contains a major actor. This method
//	assumes correct formatting but catches invalid entries.
//-----------------------------------------------------------------------------
Movie* MovieFactory::makeMovie(string line)
{
	vector<string> tokens;
	string token;
	istringstream iss(line);

	while (getline(iss, token, ','))
	{
		tokens.push_back(token);
	}

	if (tokens.size() != 5)
	{
		return NULL;
	}

	Movie *toAdd;

	// 0: Movie type
	// 1: Stock number
	// 2: Director
	// 3: Title
	// 4: Year (or actor and month for classic)
	if (tokens[0] == "C")
	{
		istringstream iss(tokens[4]);
		string actorFirstName, actorLastName;
		int month, year;

		iss >> actorFirstName >> actorLastName;
		iss >> month >> year;

		toAdd = new Classic(tokens[3], tokens[2], month, year);

		static_cast<Classic *>(toAdd)->addActor(actorFirstName + " " + actorLastName);
	}
	else if (tokens[0] == "D")
	{
		toAdd = new Drama(tokens[3], tokens[2], stoi(tokens[4]));
	}
	else if (tokens[0] == "F")
	{
		toAdd = new Comedy(tokens[3], tokens[2], stoi(tokens[4]));
	}
	else
	{
		cerr << "[MOVIE FACTORY ERROR] Invalid movie type" << endl;
		return NULL;
	}

	toAdd->addStock(stoi(tokens[1]));

	return toAdd;
}
