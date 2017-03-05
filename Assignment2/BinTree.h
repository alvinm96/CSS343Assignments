/*
	Created by Alvin Manalastas
	18 January 2017
	Interface for BinTree class
*/
#pragma once
#include <iostream>
#include "nodedata.h"

using namespace std;

class BinTree
{
	friend ostream& operator<<(ostream &os, BinTree &tree);
public:
	BinTree();
	BinTree(const BinTree &rhs);
	~BinTree();

	int getHeight(const NodeData &node) const;

	void arrayToBSTree(NodeData *arr[]);
	void bstreeToArray(NodeData *arr[]);
	bool retrieve(const NodeData &node, NodeData *&foundNode);
	bool insert(NodeData *node);
	void displaySideways() const;
	void makeEmpty();
	bool operator==(const BinTree &rhs) const;
	bool operator!=(const BinTree &rhs) const;
	BinTree& operator=(const BinTree &rhs);

private:
	struct Node
	{
		NodeData *pData;
		Node *right;
		Node *left;
	};
	Node *root;

	bool insertHelper(Node *&subtree, NodeData *data);
	bool retrieveHelper(Node *&subtree, const NodeData &node, NodeData *&foundNode) const;
	void inorderWalk(Node *subtree);
	void copyTree(Node *subtree);
	void makeEmptyHelper(Node *&subtree);
	int getHeightHelper(Node *subtree, const NodeData &node) const;
	int goToLeaf(Node *subtree) const;
	bool equalsHelper(Node *subtree, Node *rSubtree) const;
	void sideways(Node *current, int level) const;
	void bstreeToArrayHelper(Node *&subtree, int &size, NodeData *arr[]);
	void arrayToBSTreeHelper(Node *&subtree, int min, int max, NodeData *arr[]);
};

