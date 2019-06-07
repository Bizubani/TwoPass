#pragma once
#include <vector>
#ifndef DFSBFS_H
#define DFSBFS_H

struct DirectedGraphNode
{
	std::vector<int> incomingEdges;
	std::vector<int> outgoingEdges;
	bool seen = false;

};

struct UndirectedGraphNode
{
	int* neighbours;
	int parent;
	int* children;
	int numberOfNeighbours;
	bool seen;
};



class GraphSearch {
	
public:
	int finishingTime = 0;
	int currentLeader = 0;
	int currentLeaderSize = 0;
	std::vector<int> leaderSizes;
	std::vector<int> finishingTimes;
	void DFS(UndirectedGraphNode* g, int start);
	void BFS(UndirectedGraphNode* g);
	void DFSReversed(std::vector<DirectedGraphNode> &g, int start);
	void DFSnoF(std::vector<DirectedGraphNode> &g, int start);
	void BFS(DirectedGraphNode* g);
};

#endif // !DFS-BFS.h

