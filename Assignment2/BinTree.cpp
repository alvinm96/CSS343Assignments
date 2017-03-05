/*
	Created by Alvin Manalastas
	18 January 2017
	This class includes the definitions for the BinTree class. A BinTree creates a
	binary search tree with additional functions.
*/
#include "stdafx.h"
#include "BinTree.h"

//-----------------BinTree-----------------------------------------------------
// Description: Default cotr
//-----------------------------------------------------------------------------
BinTree::BinTree()
{
	root = NULL;
}

//-----------------BinTree(const BintTree &rhs)--------------------------------
// Description: Copy cotr
//-----------------------------------------------------------------------------
BinTree::BinTree(const BinTree &rhs)
{
	root = NULL;
	copyTree(rhs.root);
}

//-----------------~BinTree----------------------------------------------------
// Description: Destructor
//-----------------------------------------------------------------------------
BinTree::~BinTree()
{
	makeEmpty();
}

//-----------------getHeight---------------------------------------------------
// Description: Gets the height of the given node
//-----------------------------------------------------------------------------
int BinTree::getHeight(const NodeData &node) const
{
	return getHeightHelper(root, node);
}

//-----------------getHeightHelper---------------------------------------------
// Description: Helper for getHeight
//-----------------------------------------------------------------------------
int BinTree::getHeightHelper(Node *subtree, const NodeData &node) const
{
	if (subtree == NULL) 
	{
		return 0;
	}

	if (*subtree->pData == node) // If node is found, start counting
	{
		return goToLeaf(subtree);
	}
	else {
		return getHeightHelper(subtree->left, node) + getHeightHelper(subtree->right, node); // Go through tree until node is found or NULL
	}
}

//-----------------goToLeaf----------------------------------------------------
// Description: Counts the number of nodes away from the leaf
//-----------------------------------------------------------------------------
int BinTree::goToLeaf(Node *subtree) const
{
	if (subtree == NULL)
	{
		return 0;
	}
	else
	{
		int left = goToLeaf(subtree->left);
		int right = goToLeaf(subtree->right);
		int max = (left > right) ? left : right;
		return 1 + max;
	}
}

//-----------------arrayToBSTree-----------------------------------------------
// Description: Turns the array to a BSTree. Fills array with NULLs at the end
//-----------------------------------------------------------------------------
void BinTree::arrayToBSTree(NodeData *arr[])
{
	int size = 0;
	while (arr[size] != NULL)
	{
		size++;
	}
	arrayToBSTreeHelper(root, 0, size - 1, arr);
}

//-----------------arrayToBSTreeHelper-----------------------------------------
// Description: Helper for arrayToBSTree
//-----------------------------------------------------------------------------
void BinTree::arrayToBSTreeHelper(Node *&subtree, int min, int max, NodeData *arr[])
{
	// Base case: min is greater than max
	if (min > max)
	{
		return;
	}

	int mid = (min + max) / 2;

	Node *insNode = new Node;
	insNode->right = NULL;
	insNode->left = NULL;
	insNode->pData = arr[mid]; // Set root at middle value in array
	arr[mid] = NULL; // Set element to NULL

	subtree = insNode;

	arrayToBSTreeHelper(subtree->left, min, mid - 1, arr); // Repeat for left side, left tree
	arrayToBSTreeHelper(subtree->right, mid + 1, max, arr); // Repeat for right side, right tree

}

//-----------------bstreeToArray-----------------------------------------------
// Description: Turns BSTree to Array. Empties tree at the end
//-----------------------------------------------------------------------------
void BinTree::bstreeToArray(NodeData *arr[])
{
	int size = -1;
	bstreeToArrayHelper(root, size, arr);
	makeEmpty();
}

//-----------------bstreeToArrayHelper-----------------------------------------
// Description: Helper for bstreeToArray
//-----------------------------------------------------------------------------
void BinTree::bstreeToArrayHelper(Node *&subtree, int &size, NodeData *arr[])
{
	if (subtree == NULL)
	{
		return;
	}
	bstreeToArrayHelper(subtree->left, size, arr);
	size++;
	arr[size] = subtree->pData;
	bstreeToArrayHelper(subtree->right, size, arr);
}

//-----------------retrieve----------------------------------------------------
// Description: Gets the NodeData* of a given object in the tree 
// (via pass-by-reference parameter)and to report whether the object is found.
//-----------------------------------------------------------------------------
bool BinTree::retrieve(const NodeData &node, NodeData *&foundNode)
{
	return retrieveHelper(root, node, foundNode);
}

//-----------------retrieveHelper----------------------------------------------
// Description: Helper for retrieve
//-----------------------------------------------------------------------------
bool BinTree::retrieveHelper(Node *&subtree, const NodeData &node, NodeData *&foundNode) const
{
	if (subtree == NULL)
	{
		return false;
	}
	else if (*subtree->pData == node)
	{
		foundNode = subtree->pData;
		return true;
	}
	else if (*subtree->pData < node)
	{
		return retrieveHelper(subtree->right, node, foundNode);
	}
	else
	{
		return retrieveHelper(subtree->left, node, foundNode);
	}
}

//-----------------insert------------------------------------------------------
// Description: Inserts NodeData into Binary Tree
//-----------------------------------------------------------------------------
bool BinTree::insert(NodeData *node)
{
	return insertHelper(root, node);
}

//-----------------insertHelper------------------------------------------------
// Description: Helper for insert
//-----------------------------------------------------------------------------
bool BinTree::insertHelper(Node *&subtree, NodeData *data)
{
	if (subtree == NULL)
	{
		subtree = new Node;
		subtree->pData = data;
		subtree->left = NULL;
		subtree->right = NULL;
		return true;
	}
	else if (*subtree->pData > *data)
	{
		return insertHelper(subtree->left, data);
	}
	else if (*subtree->pData < *data)
	{
		return insertHelper(subtree->right, data);
	}
	else
	{
		return false;
	}
}

//-----------------displaySideways---------------------------------------------
// Description: Displays tree sideways. Implementation given
//-----------------------------------------------------------------------------
void BinTree::displaySideways() const
{
	sideways(root, 0);
}

//-----------------sideways----------------------------------------------------
// Description: Displays tree sideways. Implementation given
//-----------------------------------------------------------------------------
void BinTree::sideways(Node *current, int level) const
{
	if (current != NULL)
	{
		level++;
		sideways(current->right, level);

		for (int i = level; i >= 0; i--)
		{
			cout << "    ";
		}
		cout << *current->pData << endl;
		sideways(current->left, level);
	}
}

//-----------------makeEmpty---------------------------------------------------
// Description: Empties array
//-----------------------------------------------------------------------------
void BinTree::makeEmpty()
{
	makeEmptyHelper(root);
}

//-----------------makeEmptyHelper---------------------------------------------
// Description: Helper for makeEmpty
//-----------------------------------------------------------------------------
void BinTree::makeEmptyHelper(Node *&subtree)
{
	if (subtree == NULL)
	{
		return;
	}

	if (subtree->left != NULL)
	{
		makeEmptyHelper(subtree->left);
	}

	if (subtree->right != NULL)
	{
		makeEmptyHelper(subtree->right);
	}

	delete subtree;
	subtree = NULL;
}

//-----------------operator==--------------------------------------------------
// Description: Checks if trees are equal
//-----------------------------------------------------------------------------
bool BinTree::operator==(const BinTree &rhs) const
{
	return equalsHelper(root, rhs.root);
}

//-----------------operator!=--------------------------------------------------
// Description: Checks if trees are not equal
//-----------------------------------------------------------------------------
bool BinTree::operator!=(const BinTree &rhs) const
{
	return !equalsHelper(root, rhs.root);
}

//-----------------equalsHelper------------------------------------------------
// Description: Helper for (==)
//-----------------------------------------------------------------------------
bool BinTree::equalsHelper(Node *subtree, Node *rSubtree) const
{
	if ((subtree == NULL && rSubtree != NULL) || (subtree != NULL && rSubtree == NULL)) // If one of the subtrees are NULL
	{
		return false;
	}
	if (subtree == NULL && rSubtree == NULL) // Both are NULL
	{
		return true;
	}

	if (*subtree->pData != *rSubtree->pData)
	{
		return false;
	}
	else 
	{
		// Recursive through left and right side of tree
		return equalsHelper(subtree->left, rSubtree->left) && equalsHelper(subtree->right, rSubtree->right);
	}
}

//-----------------operator=---------------------------------------------------
// Description: Assigns BinTree
//-----------------------------------------------------------------------------
BinTree& BinTree::operator=(const BinTree &rhs)
{
	if (*this == rhs)
	{
		return *this;
	}
	makeEmpty();
	copyTree(rhs.root);
	return *this;
}

//-----------------inorderWalk-------------------------------------------------
// Description: Prints tree using in order traversal
//-----------------------------------------------------------------------------
void BinTree::inorderWalk(Node *subtree)
{
	if (subtree == NULL)
	{
		cout << "";
		return;
	}
	inorderWalk(subtree->left);
	cout << *subtree->pData << " ";
	inorderWalk(subtree->right);
}

//-----------------copyTree----------------------------------------------------
// Description: Copies tree
//-----------------------------------------------------------------------------
void BinTree::copyTree(Node *subtree)
{
	if (subtree == NULL)
	{
		return;
	}
	insert(subtree->pData);
	copyTree(subtree->left);
	copyTree(subtree->right);
}

//-----------------operator<<-------------------------------------------------
// Description: Prints tree using in order traversal
//-----------------------------------------------------------------------------
ostream& operator<<(ostream &os, BinTree &tree)
{
	tree.inorderWalk(tree.root);
	os << endl;
	return os;
}
