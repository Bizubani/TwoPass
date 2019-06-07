// Kosarajus Two Pass.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "DFS-BFS.h"
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#define ARRAYSIZE 875714

void DFSLoop(std::vector<DirectedGraphNode> &graph);

int main()
{
	std::ifstream inputFile;
	std::string fileName = "SCC.txt";
	inputFile.open(fileName); // open file
	int currentNode = 1; // refers to node being processed and used to reference its array position by currentNode-1
	int nextFromFile;
	int count = 1; // control variable to determine this is the first or second number on a specific line
	std::vector<DirectedGraphNode> myGraph(ARRAYSIZE);
	if (inputFile.is_open())
	{
		while (true)
		{
			if (inputFile.fail())
			{
				break;
			}
			else
			{
				//check first number against current node
				inputFile >> nextFromFile;

				if (count % 2 == 1)
				{
					currentNode = nextFromFile; // when we change line, the first number read is the current node
				}
				if (currentNode != nextFromFile)
				{
					//std::cout << nextFromFile << " " << std::flush;
					myGraph[currentNode - 1].outgoingEdges.push_back(nextFromFile);
					myGraph[nextFromFile - 1].incomingEdges.push_back(currentNode);
				}
				
			}
			count++;
		}
	}
	else
	{
		std::cout << "A technical difficulty was encountered while reading in  " + fileName + " \nPlease double check file name" << std::endl;
	}

	DFSLoop(myGraph);
	
	inputFile.close();
}


void DFSLoop(std::vector<DirectedGraphNode> &graph)
{
	GraphSearch searchTools; 
	int currentNode = ARRAYSIZE - 1;
	while (currentNode >= 0)
	{
		if (graph[currentNode].seen == false)
		{
			searchTools.DFSReversed(graph, currentNode);
		}
		currentNode--;
	}

	std::cout << " \nCompleted the first depth first search. " << std::endl;

	currentNode = ARRAYSIZE - 1;

	while (currentNode >= 0)
	{
		int specialSelectionNode = searchTools.finishingTimes[currentNode];

		if (graph[specialSelectionNode].seen == true)
		{
			searchTools.currentLeader = specialSelectionNode;
			//std::cout << searchTools.currentLeader + 1 << "" <<std::endl;
			searchTools.DFSnoF(graph, specialSelectionNode);
			searchTools.leaderSizes.push_back(searchTools.currentLeaderSize);
			searchTools.currentLeaderSize = 0;
		}
		currentNode--;
	}

	std::cout << "\n\n" << std::endl;
	for (currentNode = 0; currentNode < searchTools.leaderSizes.size(); currentNode++)
	{
		if(searchTools.leaderSizes[currentNode] > 150)
		std::cout << searchTools.leaderSizes[currentNode] << " \t" << std::flush;
	}
}


// 
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu