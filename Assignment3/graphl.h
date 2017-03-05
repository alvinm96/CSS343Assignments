#pragma once
#include "nodedata.h"
#include <fstream>
#include <iostream>
#include <climits>

using namespace std;

const int MAXNODESL = 100;

class GraphL
{
public:
	GraphL();
	~GraphL();

	void buildGraph(ifstream &file); // Builds up graph node information and adjacency list of edges between each node ready from a data file
	void displayGraph(); // Displays each node information and edge in the graph
	void depthFirstSearch(); // Makes a dfs and displays each node in depth-first order

private:
	struct EdgeNode;
	struct GraphNode
	{
		EdgeNode *edgeHead;
		NodeData *data;
		bool visited;
	};
	
	struct EdgeNode
	{
		int adjGraphNode;
		EdgeNode *nextEdge;
	};

	int size;
	GraphNode adjList[MAXNODESL + 1];

	void initTable();
	void resetTable();
	void dfs(int v);
	void deleteHelper(int v);
};

