// Dependencies.cpp : Defines the entry point for the console application.
//

#include <vector>
#include <map>
#include <sstream>
#include <iostream>
#include <stack>

std::map<char, int> m;
std::vector<std::vector<char>> graph;
std::vector<bool> visited;
std::vector<bool> backEdge;
char projects[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
std::stack<char> topoSortStack;

void insertEdge(char _before, char _after)
{
	graph.at(m[_before]).push_back(_after);
}

bool findCycle(char _v)
{
	int index = m[_v];
	if (!visited.at(index))
	{
		visited.at(index) = true;
		backEdge.at(index) = true;
		for (int i = 0; i < graph.at(index).size(); ++i)
		{
			int nextIndex = m[graph.at(index).at(i)];
			if (!visited.at(nextIndex) && findCycle(projects[nextIndex]))
				return true;
			else if (backEdge.at(nextIndex))
				return true;
		}
	}
	backEdge.at(index) = false;
	return false;
}

void clearVectors()
{
	visited.clear();
	backEdge.clear();
	for (int i = 0; i < 6; ++i)
	{
		visited.push_back(false);
		backEdge.push_back(false);
	}
}

void topoSort(char _v) 
{
	int index = m[_v];
	visited.at(index) = true;
	for (int i = 0; i < graph.at(index).size(); ++i)
	{
		int nextIndex = m[graph.at(index).at(i)];
		if (!visited.at(nextIndex))
			topoSort(projects[nextIndex]);
	}

	topoSortStack.push(_v);
}


// Implemented DFS
int main()
{
	
	for (int i = 0; i < 6; ++i)
	{
		m[projects[i]] = i;
		graph.push_back(std::vector<char>());
	}

	clearVectors();

	insertEdge('a', 'd');
	insertEdge('f', 'b');
	insertEdge('b', 'd');
	insertEdge('f', 'a');
	insertEdge('d', 'c');
	insertEdge('f', 'e');
	insertEdge('e', 'f');

	bool isValid;
	// Just brute force all paths until we hopefully start from the correct node
	for (int i = 0; i < 6; ++i)
	{
		isValid = !findCycle(projects[i]);
		if (!isValid)
			break;
	}

	if (!isValid)
		std::cout << "Error: Graph contains cycle!";
	else
	{
		clearVectors();
		for (int i = 0; i < 6; ++i)
		{
			if (visited.at(i) == false)
				topoSort(projects[i]);
		}
		while (topoSortStack.empty() == false)
		{
			std::cout << topoSortStack.top() << " ";
			topoSortStack.pop();
		}
		return 0;
	}

    return 1;
}






