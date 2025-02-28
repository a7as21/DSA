#pragma once

#include <iostream>
#include <vector>
#include <stack>
#include <queue>


class Graph{

	int vertices;
	std::vector<std::vector<int>> adjList;

public:
	Graph(int v) : vertices(v), adjList(v) {}

	void addEdge(int u, int v) {
		adjList[u].push_back(v);
	}


	void DFS(int startVertex) {

		std::vector<bool> visited(vertices, false);
		std::stack<int> stack;

		stack.push(startVertex);

		while(!stack.empty()) {

			int currentVertex = stack.top();
			stack.pop();

			if(!visited[currentVertex]) {
				std::cout << currentVertex << " ";
				visited[currentVertex] = true;
			}

			for(int neighbor : adjList[currentVertex]) {
				if(!visited[neighbor]){
					stack.push(neighbor);
					}
			}
		}
		std::cout << std::endl;
	}


	void BFS(int startVertex) {
        std::vector<bool> visited(vertices, false);
        std::queue<int> q;

        q.push(startVertex);
        visited[startVertex] = true;

        std::cout << "BFS traversal starting from node " << startVertex << ": ";

        while (!q.empty()) {
            int currentVertex = q.front();
            q.pop();

            std::cout << currentVertex << " ";

            for (int neighbor : adjList[currentVertex]) {
                if (!visited[neighbor]) {
                    q.push(neighbor);       
                    visited[neighbor] = true;
                }
            }
        }
        std::cout << std::endl;
    }
};