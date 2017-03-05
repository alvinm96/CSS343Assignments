// Assignment4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BSTree.h"
#include "Movie.h"
#include "Comedy.h"
#include "Drama.h"

#include <string>
#include <iostream>

using namespace std;

int main()
{
	Comedy test("test", "asdf M", 2000);
	Drama test2("adsf", "asdfds M", 2040);

	cout << (test == test2);

    return 0;
}

