#include "stdafx.h"
#include "Store.h"

Store::Store()
{
}


Store::~Store()
{
}

void Store::readCommands(ifstream &file)
{
	while (!file.eof())
	{
		string line;
		getline(file, line);

		Transaction *trans = TransactionFactory::makeTrans(line[0]);

		if (line[0] == 'I')
		{
			inventory();
		}
		else if (line[0] == 'H')
		{
			trans->processTrans(line, classicTree, customerTable);
		}

		if (line.length() > 6)
		{
			if (line[9] == 'C')
			{
				trans->processTrans(line, classicTree, customerTable);
			}
			else if (line[9] == 'F')
			{
				trans->processTrans(line, comedyTree, customerTable);
			}
			else if (line[9] == 'D')
			{
				trans->processTrans(line, dramaTree, customerTable);
			}
			else
			{
				cout << "[TRANSACTION ERROR] Transaction does not exist" << endl;
			}
		}
	}
}

void Store::readCustomers(ifstream & file)
{
	while (!file.eof())
	{
		string line;
		getline(file, line);

		if (line.length() > 0)
		{
			int id = stoi(line.substr(0, 4));
			string name = line.substr(5, line.length());
			customerTable.addCustomer(id, name);
		}
	}

	file.close();
}

void Store::readMovies(ifstream &file)
{
	while (!file.eof())
	{
		string line;
		getline(file, line);

		Movie *toAdd = MovieFactory::makeMovie(line);
		if (line[0] == 'C')
		{
			if (!classicTree.insert(toAdd)) // false means movie already exists, update stock instead
			{
				vector<string> tokens;
				string token;
				istringstream iss(line);

				while (getline(iss, token, ','))
				{
					tokens.push_back(token);
				}

				istringstream iss2(tokens[4]);
				string actorFirstName, actorLastName;
				iss2 >> actorFirstName >> actorLastName;

				Movie *toUpdate;
				classicTree.retrieve(toAdd, toUpdate); // should return true at this point
				toUpdate->addStock(stoi(tokens[1]));
				static_cast<Classic *>(toUpdate)->addActor(actorFirstName + " " + actorLastName);
			}
		}
		else if (line[0] == 'D')
		{
			dramaTree.insert(toAdd);
		}
		else if (line[0] == 'F')
		{
			comedyTree.insert(toAdd);
		}
	}
	file.close();
}

void Store::inventory()
{
	cout << endl << "DRAMA" << endl << dramaTree << endl;
	cout << endl << "COMEDY" << endl << comedyTree << endl;
	cout << endl << "CLASSIC" << endl << classicTree;
}
