#include "stdafx.h"
#include "Movie.h"


Movie::Movie()
{
}


Movie::~Movie()
{
}

int Movie::getStockCount() const
{
	return totalStock;
}

string Movie::getDirector() const
{
	return director;
}

string Movie::getTitle() const
{
	return title;
}

int Movie::getYear() const
{
	return year;
}

void Movie::addStock(int num)
{
	totalStock += num;
}

void Movie::subtractStock(int num)
{
	if (num > totalStock)
	{
		cerr << "[MOVIE ERROR] Number subtracted is greater than stock count." << endl;
		return;
	}
}

void Movie::setDirector(string name)
{
	director = name;
}

void Movie::setTitle(string title)
{
	this->title = title;
}

void Movie::setYear(int year)
{
	this->year = year;
}

bool Movie::operator==(const Movie &rhs) const
{
	return this->getTitle() == rhs.getTitle() &&
		this->getYear() == rhs.getYear() &&
		this->getDirector() == rhs.getDirector();
}

bool Movie::operator!=(const Movie &rhs) const
{
	return !(*this == rhs);
}

bool Movie::operator>(const Movie &rhs) const
{
	return false;
}

bool Movie::operator<(const Movie &rhs) const
{
	return false;
}

Movie & Movie::operator=(const Movie &rhs)
{
	return *this;
}
