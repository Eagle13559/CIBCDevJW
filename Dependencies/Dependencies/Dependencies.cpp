// Dependencies.cpp : Defines the entry point for the console application.
//

#include <vector>
#include <map>
#include <sstream>
#include <iostream>

std::map<char, int> m;
std::vector<std::vector<char>> graph;
std::vector<bool> visited;
std::stringstream ss;
char projects[] = { 'a', 'b', 'c', 'd', 'e', 'f' };

void insertEdge(char _before, char _after)
{
	graph.at(m[_before]).push_back(_after);
}

void DFS(char _v)
{
	int index = m[_v];
	visited.at(index) = true;
	ss << " " << _v;
	for (int i = 0; i < graph.at(index).size(); ++i)
	{
		int nextIndex = m[graph.at(index).at(i)];
		if (!visited.at(nextIndex))
		{
			DFS(graph.at(index).at(i));
		}
	}
}

void clearVectors()
{
	visited.clear();
	for (int i = 0; i < 6; ++i)
	{
		visited.push_back(false);
	}
	ss.str("");
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
	//insertEdge('f', 'e');

	// Just brute force all paths until we hopefully start from the correct node
	for (int i = 0; i < 6; ++i)
	{
		DFS(projects[i]);
		bool isValid = true;
		for (int j = 0; j < visited.size(); ++j)
		{
			if (visited.at(j) == false)
			{
				isValid = false;
				break;
			}
		}
		if (isValid)
		{
			std::cout << ss.str() << "\n";
			return 0;
		}
		else
		{
			clearVectors();
		}
	}

	std::cout << "Error: Unable to find list!";

    return 1;
}






