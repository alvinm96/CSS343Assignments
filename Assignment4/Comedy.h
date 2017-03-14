/*
	The Comedy class is a subclass of Movie. Comedy movies are associated with
	the letter 'F'. Comedy movies are sorted by title then the year it released.
*/

#pragma once
#include "Movie.h"

class Comedy: public Movie
{
public:
	Comedy(string title, string director, int year);
	Comedy(string title, int year);
	~Comedy();

	virtual bool operator==(const Movie &rhs) const;
	virtual bool operator!=(const Movie &rhs) const;
	virtual bool operator>(const Movie &rhs) const;
	virtual bool operator<(const Movie &rhs) const;
	virtual Comedy& operator=(const Movie &rhs);
};

