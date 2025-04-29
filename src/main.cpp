#include "Graph.h"
#include <iostream>
#include <thread>
#include <vector>
#include <future>
#include <cstring>

using namespace std;

int main(){
    // Definicja dwóch różnych grafów
    Graph graph1(5);
    graph1.addEdge(0, 1);
    graph1.addEdge(0, 2);
    graph1.addEdge(1, 3);
    graph1.addEdge(1, 4);

    graph1.printGraph();

    Graph graph2(4);
    graph2.addEdge(0, 1);
    graph2.addEdge(0, 2);
    graph2.addEdge(1, 2);
    graph2.addEdge(2, 0);
    graph2.addEdge(2, 3);
    graph2.addEdge(3, 3);

    graph2.printGraph();

    // Funkcja lambda do uruchomienia DFS
    auto dfsFunction = [](Graph &g, int start)
    {
        vector<int> traversal = g.runDFSAsync(start).get();
        string bufor = "\nKolejność przeszukiwania wierzchołków: ";
        for (const auto &vertex : traversal)
        {
            // Buforowane ściezki aby uniknąć mieszania się cout-ów z roznych watków
            bufor+=(to_string(vertex)+" ");
        }
        cout<<bufor<<endl;
    };

    // Uruchomienie osobnych wątków dla każdego grafu
    thread thread1(dfsFunction, ref(graph1), 0);
    thread thread2(dfsFunction, ref(graph2), 2);

    // Czekanie na zakończenie wątków
    thread1.join();
    thread2.join();

    return 0;
}