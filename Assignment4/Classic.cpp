#include "stdafx.h"
#include "Classic.h"

Classic::Classic(string title, string director, int month, int year)
{
	setTitle(title);
	setDirector(director);
	setYear(year);
	setMonth(month);
}

Classic::~Classic()
{
}

int Classic::getMonth() const
{
	return month;
}

string Classic::getActor() const
{
	return actors[0];
}

void Classic::addActor(string name)
{
	actors.push_back(name);
}

void Classic::setMonth(int month)
{
	if (month <= 0 || month > 12)
	{
		cerr << "[CLASSIC MOVIE ERROR] Invalid month." << endl;
		return;
	}
	this->month = month;
}

bool Classic::operator>(const Classic &rhs) const
{
	// Sorted by release date then major actor
	// check year -> check month ->check actor
	if (this->getYear() == rhs.getYear())
	{
		if (this->getMonth() == rhs.getMonth())
		{
			return this->getActor() > rhs.getActor();
		}
		else {
			return this->getMonth() > rhs.getMonth();
		}
	}
	return this->getYear() > rhs.getYear(); // Year not the same
}

bool Classic::operator<(const Classic &rhs) const
{
	// Sorted by release date then major actor
	// check year -> check month ->check actor
	if (this->getYear() == rhs.getYear())
	{
		if (this->getMonth() == rhs.getMonth())
		{
			return this->getActor() < rhs.getActor();
		}
		else {
			return this->getMonth() < rhs.getMonth();
		}
	}
	return this->getYear() < rhs.getYear(); // Year not the same
}

Classic & Classic::operator=(const Classic &rhs)
{
	if (*this == rhs)
	{
		return *this;
	}

	this->setTitle(rhs.getTitle());
	this->setDirector(rhs.getDirector());
	this->setYear(rhs.getYear());
	this->setMonth(rhs.getMonth());
	 
	// Copy actors
	for (int i = rhs.actors.size() -1; i >= 0; i--)
	{
		actors.push_back(rhs.actors[i]);
	}

	return *this;
}
