#include "Graph.h"
#include <iostream>
#include <thread>
#include <vector>
#include <future>
#include <string>
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

Graph defineGraph(){
    int vertices, a, b;

    while (true){
        cout << "Podaj liczbe wierzchołków grafu: ";
        cin >> vertices;
        if (vertices < 0){
            cout << "Podano nieprawidłową liczbę" << endl;
        } else{
            break;
        }
    }

    Graph graph(vertices);
    
    while (true){
        cout << "Aby zakończyć dodawanie krawędzi podaj -1" << endl;
        cout << "Podaj po spacji dwie liczby od 0 do " << vertices - 1 << " aby dodać kierunkową krawędź grafu A -> B" << endl;
        cin >> a;
        if (a == -1) break;
        cin >> b;
        if (a < 0 || a >= vertices) cout << "Podano zły wierzchołek A" << endl;
        else if (b < 0 || b >= vertices) cout << "Podano zły wierzchołek B" << endl;
        else graph.addEdge(a, b);
    }

    return graph;
}

int main(){
    #ifdef _WIN32
        SetConsoleOutputCP(CP_UTF8);
    #endif

    // Definicja dwóch różnych grafów

    cout << endl << "Graf 1:" << endl;
    
    Graph graph1 = defineGraph();
    graph1.printGraph();

    cout << endl << "Graf 2:" << endl;
    
    Graph graph2 = defineGraph();
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
    thread thread2(dfsFunction, ref(graph2), 0);

    // Czekanie na zakończenie wątków
    thread1.join();
    thread2.join();

    return 0;
}