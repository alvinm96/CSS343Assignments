#include "stdafx.h"
#include "BSTree.h"

BSTree::BSTree()
{
}

BSTree::~BSTree()
{
}

bool BSTree::insert(Movie * item)
{
	return insertHelper(head, item);
}

bool BSTree::insertHelper(Node *&subtree, Movie *item)
{
	if (subtree == NULL)
	{
		subtree = new Node();
		subtree->data = item;
		return true;
	}

	if (subtree->data < item)
	{
		return insertHelper(subtree->right, item);
	}
	else if (subtree->data > item)
	{
		return insertHelper(subtree->left, item);
	}
	else
	{
		return false;
	}
}