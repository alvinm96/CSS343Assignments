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

const vector<string> Classic::getActors() const
{
	return actors;
}

// TODO: Improve algorithm
bool Classic::containsActor(string name) const
{
	for (int i = 0; i < actors.size(); i++)
	{
		if (name == actors[i])
		{
			return true;
		}
	}
	return false;
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

bool Classic::operator==(const Movie &rhs) const
{
	const Classic &temp = static_cast<const Classic &>(rhs);
	bool containsAtLeastOneActor = false;

	// Check if at least one of the actors is in the movie, same month, same year
	for (int i = 0; i < actors.size(); i++)
	{
		if (temp.containsActor(actors[i]))
		{
			containsAtLeastOneActor = true;
		}
	}
	return this->getMonth() == temp.getMonth() &&
		   this->getYear() == temp.getYear();
}

bool Classic::operator!=(const Movie &rhs) const
{
	return !(*this == rhs);
}

bool Classic::operator>(const Movie &rhs) const
{
	const Classic &temp = static_cast<const Classic &>(rhs);
	// Sorted by release date then major actor
	// check year -> check month ->check actor
	if (this->getYear() == rhs.getYear())
	{
		if (this->getMonth() == temp.getMonth())
		{
			return this->getActor() > temp.getActor();
		}
		else {
			return this->getMonth() > temp.getMonth();
		}
	}
	return this->getYear() > rhs.getYear(); // Year not the same
}

bool Classic::operator<(const Movie &rhs) const
{
	const Classic &temp = static_cast<const Classic &>(rhs);
	// Sorted by release date then major actor
	// check year -> check month ->check actor
	if (this->getYear() == rhs.getYear())
	{
		if (this->getMonth() == temp.getMonth())
		{
			return this->getActor() < temp.getActor();
		}
		else {
			return this->getMonth() < temp.getMonth();
		}
	}
	return this->getYear() < rhs.getYear(); // Year not the same
}

Classic & Classic::operator=(const Movie &rhs)
{
	const Classic &temp = static_cast<const Classic &>(rhs);

	if (*this == rhs)
	{
		return *this;
	}

	this->setTitle(rhs.getTitle());
	this->setDirector(rhs.getDirector());
	this->setYear(rhs.getYear());
	this->setMonth(temp.getMonth());
	 
	// Copy actors
	for (int i = 0; i < actors.size(); i++)
	{
		actors.push_back(temp.actors[i]);
	}

	return *this;
}
