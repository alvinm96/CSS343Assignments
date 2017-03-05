/*
	The Movie class is an abstract class for classes Comedy, Classic, and Drama.
	All movies have a title, the year it was released, and the director.
*/
#pragma once
#include <string>
#include <iostream>

using namespace std;

class Movie
{
public:
	virtual ~Movie();

	virtual int getStockCount() const; // Gets the total stock count of certain movie
	virtual string getDirector() const; // Gets the director's name
	virtual string getTitle() const; // Gets the title of the movie
	virtual int getYear() const; // Gets the year the movie was released
	
	virtual void addStock(int num); // Adds to the total stock
	virtual void subtractStock(int num); // Subtracts to the total stock
	virtual void setDirector(string name); // Sets the name of the director
	virtual void setTitle(string title); // Sets the title of the movie
	virtual void setYear(int year); // Sets the year the movie was released

	virtual bool operator==(const Movie &rhs) const; // Same movie title, year, director
	virtual bool operator!=(const Movie &rhs) const; // Not same movie title, year, director
	virtual bool operator>(const Movie &rhs) const;
	virtual bool operator<(const Movie &rhs) const;
	virtual Movie& operator=(const Movie &rhs);

private:
	int totalStock = 0;
	string director;
	string title;
	int year;

protected:
	Movie(); 	// Protected so it cannot be used

};

