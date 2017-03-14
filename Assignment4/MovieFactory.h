#pragma once
#include <string>
#include <sstream>
#include <iostream>

#include "Movie.h"
#include "Comedy.h"
#include "Drama.h"
#include "Classic.h"

using namespace std;

class MovieFactory
{
public:
	static Movie* makeMovie(string line);
};

