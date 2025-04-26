#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <stack>
#include <iostream>
#include <thread>
#include <functional>
#include <future>

class Graph {
public:
Graph(int vertices);
void addEdge(int src, int dest);
void DFS(int start);
void printDFS(const std::vector<int>& traversal);

// Metoda do przetwarzania DFS w osobnym wątku
std::future<std::vector<int>> runDFSAsync(int start);

private:
int numVertices;
std::vector<std::vector<int>> adjList;
};

#endif // GRAPH_H