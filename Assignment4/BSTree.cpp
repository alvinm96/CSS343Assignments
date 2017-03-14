#include "stdafx.h"
#include "BSTree.h"

BSTree::BSTree()
{
}

BSTree::~BSTree()
{
}

bool BSTree::insert(Movie *item)
{
	return insertHelper(head, item);
}

bool BSTree::retrieve(const Movie *toFind, Movie *&found)
{
	return retrieveHelper(head, toFind, found);
}

void BSTree::inOrderDisplay(ostream &os, Node *subtree) const
{
	if (subtree == NULL)
	{
		return;
	}
	inOrderDisplay(os, subtree->left);
	os << subtree->data << endl;
	inOrderDisplay(os, subtree->right);
}

bool BSTree::insertHelper(Node *&subtree, Movie *item)
{
	if (subtree == NULL)
	{
		subtree = new Node();
		subtree->data = item;
		return true;
	}

	if (*subtree->data == *item)
	{
		return false;
	}
	else if (*subtree->data > *item)
	{
		return insertHelper(subtree->left, item);
	}
	else
	{
		return insertHelper(subtree->right, item);
	}
}

bool BSTree::retrieveHelper(Node *&subtree, const Movie *toFind, Movie *&found)
{
	if (subtree == NULL)
	{
		found = NULL;
		return false;
	}

	if (*toFind == *subtree->data)
	{
		found = subtree->data;
		return true;
	}
	else if (*toFind > *subtree->data)
	{
		return retrieveHelper(subtree->right, toFind, found);
	}
	else
	{
		return retrieveHelper(subtree->left, toFind, found);
	}
}

ostream &operator<<(ostream &os, const BSTree &tree)
{
	os << "------------------------------------------------------------------------------------------------" << endl;
	os << "               Title                  |             Director             | Release Date | Stock " << endl;
	os << "------------------------------------------------------------------------------------------------" << endl;
	tree.inOrderDisplay(os, tree.head);
	os << "------------------------------------------------------------------------------------------------" << endl;
	return os;
}
