/*
	Created by Alvin Manalastas
	CSS342 Assignment 1
	This is the header file for the Poly object
*/
#pragma once
#include <iostream>
#include <string>

using namespace std;

class Poly
{
	friend ostream& operator<<(ostream& os, const Poly &poly); // Prints polynomial
	friend istream& operator>>(istream& is, Poly &poly); // Sets all terms of the polynomial. End input with "-1 -1"
public:
	// Constructors
	Poly(); // Initializes Poly to 0x^0
	Poly(int coefficient); // Initializes Poly to (coefficient)x^0
	Poly(int coefficient, int exponent); // Initializes Poly with largest power of exponent and sets the coefficient
	Poly(const Poly &rhs); // Copy constructor
	~Poly(); // Destructor

	// Getters/Setters
	int getCoeff(int n) const; // Gets the coefficient to the corresponding exponent. (n - exponent)
	int getDegree() const; // Gets the degree of the polynomial
	void setCoeff(int c, int n); // Sets the coefficient to the corresponse exponent. (c - coefficient, n - exponent)


	// Op overloads
	Poly operator+(const Poly &rhs); 
	Poly operator-(const Poly &rhs);
	Poly operator*(const Poly &rhs);

	Poly& operator+=(const Poly &rhs);
	Poly& operator-=(const Poly &rhs);
	Poly& operator*=(const Poly &rhs);

	Poly& operator=(const Poly &rhs);

	bool operator==(const Poly &rhs);
	bool operator!=(const Poly &rhs);

private:
	int *polyPtr;
	int degree;

	void initPolynomial(int n); // Initializes polynomial array to correct size and initializes values to 0 (n - polynomial size)
};

