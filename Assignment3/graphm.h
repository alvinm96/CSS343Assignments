#pragma once
#include "nodedata.h"
#include <fstream>
#include <iostream>
#include <climits>

using namespace std;

int const MAXNODES = 100;

class GraphM
{
public:
	GraphM();
	~GraphM();

	void buildGraph(ifstream &file);
	void insertEdge(int v1, int v2, int cost);
	void removeEdge(int v1, int v2);
	void findShortestPath();
	void displayAll();
	void display(int node1, int node2);

private:
	struct TableType
	{
		bool visited; // whether node has been visited
		int dist; // shortest distance from source known so far
		int path; // previous node in path of min dist
	};

	int size; // number of nodes in the graph

	NodeData data[MAXNODES + 1]; // data for graph nodes
	int C[MAXNODES + 1][MAXNODES + 1]; // Cost array, the adjacency matrix
	TableType T[MAXNODES + 1][MAXNODES + 1]; // stores visited, distance, path

	void initTable(); // Sets dist to infinity and visited to false
	int findMin(TableType table[]);
	void printPath(int from, int to);
	void printLocation(int from, int to);
	void resetTable();
};

