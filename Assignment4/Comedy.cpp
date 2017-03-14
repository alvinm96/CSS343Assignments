#include "stdafx.h"
#include "Comedy.h"


Comedy::Comedy(string title, string director, int year)
{
	setTitle(title);
	setDirector(director);
	setYear(year);
}

Comedy::Comedy(string title, int year)
{
	setTitle(title);
	setYear(year);
}

Comedy::~Comedy()
{
}

bool Comedy::operator==(const Movie &rhs) const
{
	return this->getTitle() == rhs.getTitle() &&
		   this->getYear() == rhs.getYear();
}

bool Comedy::operator!=(const Movie & rhs) const
{
	return !(*this == rhs);
}

bool Comedy::operator>(const Movie &rhs) const
{
	// Sorted by title then year
/*	if (this->getTitle() == rhs.getTitle())
	{
		return this->getYear() > rhs.getYear();
	}
	return this->getTitle() > rhs.getTitle();*/

	if (this->getTitle() > rhs.getTitle())
	{
		return true;
	}
	else if (this->getTitle() == rhs.getTitle())
	{
		return (this->getYear() > rhs.getYear());
	}
	return false;
}

bool Comedy::operator<(const Movie &rhs) const
{
	// Sorted by title then year
	if (this->getTitle() < rhs.getTitle())
	{
		return true;
	}
	else if (this->getTitle() == rhs.getTitle())
	{
		return (this->getYear() < rhs.getYear());
	}
	return false;
}

Comedy& Comedy::operator=(const Movie &rhs)
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
