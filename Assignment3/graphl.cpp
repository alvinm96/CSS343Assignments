/*
	Created by Alvin Manalastas
	13 February 2017
	Assignment 3
	This class implements the depth first search algorithm. This class will be 
	able to read a data file and will be able to print out the order for the 
	depth first search algorithm.
*/
//#include "stdafx.h"
#include "graphl.h"

//------------------------Graph------------------------------------------------
// Initializes the table
//-----------------------------------------------------------------------------
GraphL::GraphL()
{
	initTable();
}

//-----------------------~Graph------------------------------------------------
// Deletes the allocated NodeData
//-----------------------------------------------------------------------------
GraphL::~GraphL()
{
	for (int i = 1; i <= size; i++)
	{
		if (!(adjList[i].visited))
		{
			deleteHelper(i);
		}
	}
}

//-----------------------buildGraph--------------------------------------------
// Builds up graph node information and adjacency matrix of edges between each
// node reading from a data file.
//-----------------------------------------------------------------------------
void GraphL::buildGraph(ifstream &file)
{
	int node1 = -1;
	int node2 = -1;

	file >> size; // Get number of nodes

	if (size > 0)
	{
		string s;
		getline(file, s);

		for (int i = 1; i <= size; i++)
		{
			NodeData *insData = new NodeData;
			insData->setData(file);
			adjList[i].data = insData;
		}

		file >> node1 >> node2;

		while ((node1 != 0) && (node2 != 0) && (!file.eof()))
		{
			file >> node1 >> node2;

			// Make new edge node to insert
			EdgeNode *edge = new EdgeNode;
			edge->adjGraphNode = node2;

			// Null edge head
			if (adjList[node1].edgeHead == NULL)
			{
				edge->nextEdge = NULL;
				adjList[node1].edgeHead = edge;
			}
			else
			{
				edge->nextEdge = adjList[node1].edgeHead;
				adjList[node1].edgeHead = edge;
			}
		}
	}
}

//-----------------------displayGraph------------------------------------------
// Displays the node location and its edges
//-----------------------------------------------------------------------------
void GraphL::displayGraph()
{
	cout << endl << "Graph:" << endl;
	for (int i = 1; i <= size; i++)
	{
		cout << "Node " << i << "       " << *adjList[i].data << endl;
		
		EdgeNode *current = adjList[i].edgeHead;
		while (current != NULL)
		{
			cout << "  edge " << i << " " << current->adjGraphNode << endl;
			current = current->nextEdge;
		}
	}
}

//-----------------------depthFirstSearch--------------------------------------
// Implements depth first search to print paths in dfs order
//-----------------------------------------------------------------------------
void GraphL::depthFirstSearch()
{
	cout << "Depth-first ordering: ";

	for (int i = 1; i <= size; i++)
	{
		if (!(adjList[i].visited))
		{
			dfs(i);
		}
	}
	resetTable();
	cout << endl;
}

//-----------------------initTable---------------------------------------------
// Initializes all edge heads to null and visited to false
//-----------------------------------------------------------------------------
void GraphL::initTable()
{
	size = 0;
	for (int i = 0; i <= MAXNODESL; i++)
	{
		adjList[i].data = NULL;
		adjList[i].edgeHead = NULL;
		adjList[i].visited = false;
	}
}

//-----------------------resetTable--------------------------------------------
// Resets list to not visited
//-----------------------------------------------------------------------------
void GraphL::resetTable()
{
	for (int i = 0; i <= MAXNODESL; i++)
	{
		adjList[i].visited = false;
	}
}

//-----------------------dfs---------------------------------------------------
// Helper for depthFirstSearch
//-----------------------------------------------------------------------------
void GraphL::dfs(int v)
{
	adjList[v].visited = true;
	cout << v << " ";

	int w;
	EdgeNode *current = adjList[v].edgeHead;
	// For each adjacent edges of v
	while (current != NULL)
	{
		w = current->adjGraphNode;
		if (!(adjList[w].visited))
		{
			dfs(w);
		}
		current = current->nextEdge; // Move edges
	}
}

void GraphL::deleteHelper(int v)
{
	adjList[v].visited = true;
	
	delete adjList[v].data;
	adjList[v].data = NULL;

	int w;
	EdgeNode *current = adjList[v].edgeHead;
	// For each adjacent edges of v
	while (current != NULL)
	{
		w = current->adjGraphNode;
		EdgeNode *temp = current->nextEdge;
		adjList[v].edgeHead = NULL;
		if (!(adjList[w].visited))
		{
			deleteHelper(w);
		}
		delete current;

		current = temp; // Move edges
	}
}
