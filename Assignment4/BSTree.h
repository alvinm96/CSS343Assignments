/*
	BSTree to hold movies
*/
#pragma once
#include "Movie.h"

class BSTree
{
	friend ostream& operator<<(ostream &os, const BSTree &tree);
public:
	BSTree();
	~BSTree();

	bool insert(Movie *movie);
	bool remove(Movie *movie);
	bool retrieve(const Movie *toFind, Movie *&found);

private:
	struct Node 
	{
		Movie *data;
		Node *left = NULL;
		Node *right = NULL;
	};
	Node *head = NULL;

	void inOrderDisplay(ostream &os, Node *subtree) const;
	bool insertHelper(Node *&subtree, Movie *item);
	bool removeHelper(Node *&subtree, Movie *item);
	bool retrieveHelper(Node *&subtree, const Movie *toFind, Movie *&found);
};


