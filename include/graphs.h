// Description: This file contains the function declarations for graphs.
#ifndef GRAPHS_H
#define GRAPHS_H

#include <vector>

struct edge {
    int node1;
    int node2;
};

std::vector<std::vector<int>> adjacencyMatrixToAdjacencyList(const std::vector<std::vector<int>>& AdjMatrix);

std::vector<std::vector<int>> nodeListToAdjacencyMatrix(const std::vector<std::vector<int>>& nodeList);

std::vector<edge> adjacencyMatrixToEdgeList(const std::vector<std::vector<int>>& AdjMatrix);

std::vector<std::vector<int>> edgeListToAdjacencyMatrix(const std::vector<edge> & edgeList);

std::vector<edge> nodeListToEdgeList(const std::vector<std::vector<int>>& nodeList);

std::vector<std::vector<int>> edgeListToNodeList(const std::vector<edge>& edgeList);

void printAdjList(const std::vector<std::vector<int>>& AdjList);

void printAdjMatrix(const std::vector<std::vector<int>>& AdjMatrix);

void printEdgeList(const std::vector<edge>& edgeList);

void dfsMain(const std::vector<std::vector<int>>& AdjList, int source);

void dfsRecursive(const std::vector<std::vector<int>>& AdjList, int node, std::vector<bool>& visited);

void bfs(const std::vector<std::vector<int>>& AdjList, int node);

bool checkExistanceOfPath(const std::vector<std::vector<int>>& AdjList, int source, int destination);

bool pathSearch(const std::vector<std::vector<int>>& AdjList, int source, int destination, std::vector<bool>& visited);

void displayGraphsMenu();

void handleGraphs();


#endif // GRAPHS_H