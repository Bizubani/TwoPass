#include "DFS-BFS.h"
#include <iostream>

// implementation of Depth First Search using recusion to mimic the stack
void GraphSearch::DFSReversed(std::vector<DirectedGraphNode> &g, int start)
{ 
	int count = 0;
	int nextNode;
	g[start].seen = true; // mark start node as seen
	while (count < g[start].incomingEdges.size())
	{
		nextNode = g[start].incomingEdges[count];//get the nextNode to be checked and then increment the count
		count++;
		if (g[nextNode-1].seen == true)
		{
			//if seen, continue
		}// end if
		else
		{
			DFSReversed(g, nextNode-1); // recurse on the graph starting from the nextNode
		}//end else
	}//end while
	finishingTimes.push_back(start);
	//std::cout << "Node " << start + 1 << " finished in position " << finishingTime + 1 << std::endl;
	finishingTime++;
	return;
}//end DFS

void GraphSearch::DFS(UndirectedGraphNode* g, int start)
{
	int edgesToExplore = g[start].numberOfNeighbours;
	int count = 0;
	g[start].seen = true; // mark start node as seen
	while (count < edgesToExplore)
	{
		int nextNode = g[start].neighbours[count++];//get the nextNode to be checked and then increment the count
		if (g[nextNode].seen == true)
		{
			//if seen, continue
		}// end if
		else
		{
			DFS(g, nextNode); // recurse on the graph starting from the nextNode
		}//end else
	}//end while
	return;
}

void GraphSearch::BFS(DirectedGraphNode* g)
{

}

void GraphSearch::BFS(UndirectedGraphNode* g)
{

}
//Depth first search with no finishing times computations but counting the size of the leaders.
//also works with reverse logic, as all nodes in the graph were seen in the first pass.
void GraphSearch::DFSnoF(std::vector<DirectedGraphNode>& g, int start)
{
	int edgesToExplore = g[start].outgoingEdges.size();
	int count = 0;
	g[start].seen = false; // mark start node as seen
	//std::cout << "current leader: " << currentLeader << " is the leader of node: " << start << std::endl;
	currentLeaderSize++;
	while (count < edgesToExplore)
	{
		int nextNode = g[start].outgoingEdges[count];//get the nextNode to be checked and then increment the count
		count++;
		if (g[nextNode-1].seen == false)
		{
			//if seen, continue
		}// end if
		else
		{
			DFSnoF(g, nextNode-1); // recurse on the graph starting from the nextNode
		}//end else
	}//end while

	return;
}//end DFS





