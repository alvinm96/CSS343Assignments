/*
	BSTree to hold movies
*/
#pragma once
#include "Movie.h"

class BSTree
{
public:
	BSTree();
	~BSTree();

	bool insert(Movie *movie);
	bool remove(Movie *movie);

private:
	struct Node 
	{
		Movie *data;
		Node *left = NULL;
		Node *right = NULL;
	};
	Node *head = NULL;

	bool insertHelper(Node *&subtree, Movie *item);
	bool removeHelper(Node *&subtree, Movie *item);
};


