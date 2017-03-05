/*
	The Classic class is a subclass of Movie. Classic movies are associated with the
	letter 'C'. Classics are sorted by Release date, then major actor. Major actor
	is formatted as first name (string) and last name (string), which are separated 
	by a space. Release data contains a month (int) and year (int). A Classic movie
	may contain separate lines but they both use the same inventory.
*/
#pragma once
#include <vector>
#include "Movie.h"

using namespace std;

class Classic: public Movie
{
public:
	Classic(string title, string director, int month, int year);
	~Classic();
	
	int getMonth() const; // Get the month movie was released
	string getActor() const;

	void addActor(string name); // Add actor to vector of major actors
	void setMonth(int month); // Set the month

	virtual bool operator>(const Classic &rhs) const;
	virtual bool operator<(const Classic &rhs) const;
	virtual Classic& operator=(const Classic &rhs);
private:
	vector<string> actors;
	int month;
};

