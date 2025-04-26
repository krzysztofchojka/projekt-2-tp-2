#include "Graph.h"
#include <iostream>
#include <thread>
#include <vector>
#include <future>

using namespace std;

int main() {
// Definicja dwóch różnych grafów
Graph graph1(5);
graph1.addEdge(0, 1);
graph1.addEdge(0, 2);
graph1.addEdge(1, 3);
graph1.addEdge(1, 4);

Graph graph2(4);
graph2.addEdge(0, 1);
graph2.addEdge(0, 2);
graph2.addEdge(1, 2);
graph2.addEdge(2, 0);
graph2.addEdge(2, 3);
graph2.addEdge(3, 3);

// Funkcja lambda do uruchomienia DFS
auto dfsFunction = [](Graph& g, int start) {
vector<int> traversal = g.runDFSAsync(start).get();
cout << "DFS Traversal (async): ";
for (const auto& vertex : traversal) {
cout << vertex << " ";
}
cout << endl;
};

// Uruchomienie osobnych wątków dla każdego grafu
thread thread1(dfsFunction, ref(graph1), 0);
thread thread2(dfsFunction, ref(graph2), 2);

// Czekanie na zakończenie wątków
thread1.join();
thread2.join();

return 0;
}