/*
    Created by Alvin Manalastas
    31 Jan 2017
    Assignment 3
    This class implements the Dijkstra's algorithm. This class will be able to 
	read a data file and will be able to find the lowest cost paths and diplay 
	the cost and path from every node to every other node. Another display 
	routine will output one path in detail.
*/
//#include "stdafx.h"
#include "graphm.h"

//-----------------------Graph-------------------------------------------------
// Initializes table
//-----------------------------------------------------------------------------
GraphM::GraphM()
{
	initTable();
}

GraphM::~GraphM()
{
}
                                                                               
//-----------------------buildGraph--------------------------------------------
// Builds up graph node information and adjacency matrix of edges between each
// node reading from a data file.
//-----------------------------------------------------------------------------
void GraphM::buildGraph(ifstream &file)
{
	int node1 = -1;
	int node2 = -1;
	int dist = -1;

	file >> size; // Get number of nodes

	if (size > 0)
	{
		string s;
		getline(file, s);
		for (int i = 1; i <= size; i++)
		{
			data[i].setData(file);
		}

		while ((node1 != 0) && (node2 != 0) && (dist != 0) && (!file.eof()))
		{
			file >> node1 >> node2 >> dist;
			insertEdge(node1, node2, dist);
		}
	}
}

//-----------------------insertEdge--------------------------------------------
// Insert an edge into graph between two given nodes
//-----------------------------------------------------------------------------
void GraphM::insertEdge(int v1, int v2, int cost)
{
	if (v1 >= 1 && v1 <= size && v2 >= 1 && v2 <= size && cost >= 0 && cost <= INT_MAX)
	{
		C[v1][v2] = cost;
	}
}

//-----------------------removeEdge--------------------------------------------
// Remove an edge between two given nodes
//-----------------------------------------------------------------------------
void GraphM::removeEdge(int v1, int v2)
{
	C[v1][v2] = INT_MAX;
}

//-----------------------findShortestPath--------------------------------------
// Find the shortest path between every node to every other node in the graph
//-----------------------------------------------------------------------------
void GraphM::findShortestPath()
{
	for (int source = 1; source <= size; source++)
	{
		T[source][source].dist = 0;

		for (int i = 1; i <= size; i++)
		{
			int v = findMin(T[source]);
			T[source][v].visited = true;

			for (int w = 1; w <= size; w++)
			{
				if (!T[source][w].visited && C[v][w] != INT_MAX && !(T[source][w].dist < T[source][v].dist + C[v][w]))
				{
					T[source][w].path = v;

					T[source][w].dist = T[source][v].dist + C[v][w];
				}
			}
		}
	}
	resetTable();
}

//-----------------------displayAll--------------------------------------------
// Uses couts to demonstrate that the algorithm works properly
//-----------------------------------------------------------------------------
void GraphM::displayAll()
{
	cout << "Description               From node  To node  Dijkstra's  Path" << endl;
	for (int i = 1; i <= size; i++)
	{
		cout << data[i] << endl;

		for (int j = 1; j <= size; j++)
		{
			if (T[i][j].dist != 0)
			{
				cout << "                               " << i << "       " << j << "        ";

				if (T[i][j].dist > 0 && T[i][j].dist < INT_MAX)
				{
					cout << T[i][j].dist;
					cout << "        " << i << " ";
					printPath(i, j);
				}
				else if (T[i][j].dist == INT_MAX)
				{
					cout << "---";
				}
				cout << endl;
			}
		}
	}
	cout << endl;
}

//-----------------------display-----------------------------------------------
// Uses couts to display the shortest distance with path info between the 
// fromNode to toNode
//-----------------------------------------------------------------------------
void GraphM::display(int node1, int node2)
{
	if (T[node1][node2].dist != 0)
	{
		cout << "   " << node1 << "       " << node2 << "        ";

		if (T[node1][node2].dist > 0 && T[node1][node2].dist < INT_MAX)
		{
			cout << T[node1][node2].dist;
			cout << "        " << node1 << " ";
			printPath(node1, node2);
			cout << endl << data[node1];
			printLocation(node1, node2);
		}
		else if (T[node1][node2].dist == INT_MAX)
		{
			cout << "---";
		}
		cout << endl;
	}
}

//-----------------------initTable---------------------------------------------
// Sets dist to infinity and visited to false
//-----------------------------------------------------------------------------
void GraphM::initTable()
{
	for (int x = 0; x <= MAXNODES; x++)
	{
		for (int y = 0; y <= MAXNODES; y++)
		{
			T[x][y].visited = false;
			T[x][y].path = 0;
			T[x][y].dist = INT_MAX;
			C[x][y] = INT_MAX;
		}
	}
}

//-----------------------findMin-----------------------------------------------
// Finds for V
//-----------------------------------------------------------------------------
int GraphM::findMin(TableType table[])
{
	int min = INT_MAX;
	int index = 0;

	for (int i = 1; i <= size; i++)
	{
		if (!(table[i].visited) && table[i].dist <= min)
		{
			index = i;
			min = table[i].dist;
		}
	}
	return index;
}

//-----------------------printPath---------------------------------------------
// Recursively prints the shortest path
//-----------------------------------------------------------------------------
void GraphM::printPath(int from, int to)
{
	int index = 1;
	if (T[from][to].dist != INT_MAX)
	{
		if (from == to)
		{
			return;
		}
		index = to;
		printPath(from, T[from][to].path);
	}
	cout << index << " ";
}

//-----------------------printLocation-----------------------------------------
// Prints the location associated with the node
//-----------------------------------------------------------------------------
void GraphM::printLocation(int from, int to)
{
	int index = 1;
	if (T[from][to].dist != INT_MAX)
	{
		if (from == to)
		{
			return;
		}
		index = to;
		printLocation(from, T[from][to].path);
	}
	cout << endl << data[index];
}

//-----------------------resetTable--------------------------------------------
// Resets the visited values back to false
//-----------------------------------------------------------------------------
void GraphM::resetTable()
{
	for (int i = 1; i <= size; i++)
	{
		for (int j = 1; j <= size; j++)
		{
			T[i][j].visited = false;
		}
	}
}
