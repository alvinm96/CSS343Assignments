#include "stdafx.h"
#include "Comedy.h"


Comedy::Comedy(string title, string director, int year)
{
	setTitle(title);
	setDirector(director);
	setYear(year);
}

Comedy::~Comedy()
{
}

bool Comedy::operator>(const Comedy &rhs) const
{
	// Sorted by title then year
	if (this->getTitle() == rhs.getTitle())
	{
		return this->getYear() > rhs.getYear();
	}
	return this->getTitle() > rhs.getTitle();
}

bool Comedy::operator<(const Comedy &rhs) const
{
	// Sorted by title then year
	if (this->getTitle() == rhs.getTitle())
	{
		return this->getYear() < rhs.getYear(); 
	}
	return this->getTitle() < rhs.getTitle();
}

Comedy& Comedy::operator=(const Comedy &rhs)
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
