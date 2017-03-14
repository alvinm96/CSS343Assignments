#include "stdafx.h"
#include "Drama.h"

Drama::Drama(string title, string director, int year)
{
	setTitle(title);
	setDirector(director);
	setYear(year);
}

Drama::Drama(string title, string director)
{
	setTitle(title);
	setDirector(director);
}

Drama::~Drama()
{
}

bool Drama::operator==(const Movie &rhs) const
{
	return this->getTitle() == rhs.getTitle() &&
		   this->getDirector() == rhs.getDirector();
}

bool Drama::operator!=(const Movie &rhs) const
{
	return !(*this == rhs);
}

bool Drama::operator>(const Movie &rhs) const
{
	// Sorted by director then title
	if (this->getDirector() == rhs.getDirector())
	{
		return this->getTitle() > rhs.getTitle();
	}
	return this->getDirector() > rhs.getDirector();
}

bool Drama::operator<(const Movie &rhs) const
{
	// Sorted by director then title
	if (this->getDirector() == rhs.getDirector())
	{
		return this->getTitle() < rhs.getTitle();
	}
	return this->getDirector() < rhs.getDirector();
}

Drama& Drama::operator=(const Movie &rhs)
{
	if (*this == rhs)
	{
		return *this;
	}

	this->setTitle(rhs.getTitle());
	this->setDirector(rhs.getDirector());
	this->setYear(rhs.getYear());

	return *this;
}
