/*
	The Drama class is a subclass of Movie. Drama movies are associated with the
	letter 'D'. Dramas are sorted by Director, then Title.
*/
#pragma once
#include "Movie.h"

class Drama: public Movie
{
public:
	Drama(string title, string director, int year);
	Drama(string title, string director);
	~Drama();

	virtual bool operator==(const Movie &rhs) const;
	virtual bool operator!=(const Movie &rhs) const;
	virtual bool operator>(const Movie &rhs) const;
	virtual bool operator<(const Movie &rhs) const;
	virtual Drama& operator=(const Movie &rhs); // TODO: Not needed??
};

