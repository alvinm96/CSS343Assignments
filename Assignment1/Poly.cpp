/*
		Created by Alvin Manalastas
		CSS342 Assignment 1
		This file contains the implementation for the Poly object. A Poly object contains
		an array that represents the coefficient of the polynomial. The index of the
		array corresponds to the element's exponent.
*/
#include "stdafx.h"
#include "Poly.h"

ostream & operator<<(ostream & os, const Poly & poly)
{
	for (int i = poly.getDegree(); i >= 0; i--)
	{
		// Check the degree and if coefficient is positive or negative
		if (i > 1)
		{
			if (poly.getCoeff(i) > 0)
			{
				os << " +" << poly.getCoeff(i) << "x^" << i;
			}
			else if (poly.getCoeff(i) < 0)
			{
				os << " " << poly.getCoeff(i) << "x^" << i;
			}
		}
		else if (i == 1)
		{
			if (poly.getCoeff(i) > 0)
			{
				os << " +" << poly.getCoeff(i) << "x";
			}
			else if (poly.getCoeff(i) < 0)
			{
				os << " " << poly.getCoeff(i) << "x";
			}
		}
		else
		{
			if (poly.getCoeff(i) > 0)
			{
				os << " +" << poly.getCoeff(i);
			}
			else if (poly.getCoeff(i) < 0)
			{
				os << " " << poly.getCoeff(i);
			}
		}
	}
	return os;
}

istream & operator >> (istream & is, Poly & poly)
{
	int coefficient = 0;
	int exponent = 0;

	// Continue receiving input until (-1 -1)
	while (coefficient != -1 && exponent != -1)
	{
		poly.setCoeff(coefficient, exponent);
		is >> coefficient >> exponent;
	}
	return is;
}

Poly::Poly()
{
	this->degree = 0;
	initPolynomial(1);
	*polyPtr = 0;
}

Poly::Poly(int coefficient)
{
	this->degree = 0;
	initPolynomial(1);
	*polyPtr = coefficient;
}

Poly::Poly(int coefficient, int exponent)
{
	this->degree = exponent;
	initPolynomial(exponent + 1);
	*(polyPtr + exponent) = coefficient;
}

Poly::Poly(const Poly & rhs)
{
	this->degree = rhs.getDegree(); // Copy variable
	this->polyPtr = new int[rhs.getDegree() + 1]; // Set new array

	// Copy elements to new array
	for (int i = 0; i <= degree; i++)
	{
		setCoeff(rhs.getCoeff(i), i);
	}
}

Poly::~Poly()
{
	delete[] polyPtr;
	polyPtr = NULL;
}

int Poly::getCoeff(int n) const
{
	// Out of range returns first element
	if (n < 0 || n > degree)
	{
		return *(polyPtr);
	}
	return *(polyPtr + n);
}

int Poly::getDegree() const
{
	return degree;
}

void Poly::setCoeff(int c, int n)
{
	if (n > degree)
	{
		int *temp = new int[n + 1]; // New temp array with correct size
		// Copy all values to temp array
		for (int i = 0; i <= degree; i++)
		{
			*(temp + i) = *(polyPtr + i);
		}

		// Set rest of values to 0
		for (int i = degree + 1; i < n; i++)
		{
			*(temp + i) = 0;
		}
		delete[] polyPtr;
		polyPtr = temp; // Change poly to temp
		degree = n; // Change degree
	}
	*(polyPtr + n) = c;
}

Poly Poly::operator+(const Poly & rhs)
{
	int largerDegree = this->getDegree() > rhs.getDegree() ? this->getDegree() : rhs.getDegree(); // Find largest degree
	Poly retVal(0, largerDegree);

	// Add left poly values onto return poly
	for (int i = 0; i <= degree; i++)
	{
		*(retVal.polyPtr + i) += *(polyPtr + i);
	}

	// Add right poly values onto return poly
	for (int i = 0; i <= rhs.getDegree(); i++)
	{
		*(retVal.polyPtr + i) += *(rhs.polyPtr + i);
	}
	return retVal;
}

Poly Poly::operator-(const Poly & rhs)
{
	int largerDegree = this->getDegree() > rhs.getDegree() ? this->getDegree() : rhs.getDegree();
	Poly retVal(0, largerDegree);

	// Add left poly values onto return poly
	for (int i = 0; i <= degree; i++)
	{
		*(retVal.polyPtr + i) += *(polyPtr + i);
	}

	// Subtract right poly values with return poly
	for (int i = 0; i <= rhs.getDegree(); i++)
	{
		*(retVal.polyPtr + i) -= *(rhs.polyPtr + i);
	}
	return retVal;
}

Poly Poly::operator*(const Poly & rhs)
{
	int newDegree = this->getDegree() + rhs.getDegree(); // Get new poly degree
	Poly retVal(0, newDegree);

	for (int lPoly = 0; lPoly <= degree; lPoly++)
	{
		for (int rPoly = 0; rPoly <= rhs.getDegree(); rPoly++)
		{
			*(retVal.polyPtr + (lPoly + rPoly)) += *(polyPtr + lPoly) * *(rhs.polyPtr + rPoly);
		}
	}
	return retVal;
}

Poly & Poly::operator+=(const Poly & rhs)
{
	*this = *this + rhs;
	return *this;
}

Poly & Poly::operator-=(const Poly & rhs)
{
	*this = *this - rhs;
	return *this;
}

Poly & Poly::operator*=(const Poly & rhs)
{
	*this = *this * rhs;
	return *this;
}

Poly & Poly::operator=(const Poly & rhs)
{
	if (*this == rhs)
	{
		return *this;
	}

	polyPtr = NULL;
	delete[] polyPtr;

	this->degree = rhs.getDegree(); // Copy variable
	this->polyPtr = new int[rhs.getDegree() + 1]; // Set new array

	// Copy elements to new array
	for (int i = 0; i <= degree; i++)
	{
		this->setCoeff(rhs.getCoeff(i), i);
	}

	return *this;
}

bool Poly::operator==(const Poly & rhs)
{
	if (this->degree != rhs.getDegree())
	{
		return false;
	}
	for (int i = 0; i <= degree; i++)
	{
		return this->getCoeff(i) == rhs.getCoeff(i);
	}
	return true;
}

bool Poly::operator!=(const Poly & rhs)
{
	return !(*this == rhs);
}

void Poly::initPolynomial(int n)
{
	// Create array
	polyPtr = new int[n];
	// Set all values to zero
	for (int i = 0; i < n; i++)
	{
		setCoeff(0, i);
	}
}
