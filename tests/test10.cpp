#include "Graph.h"
#include <cassert>
#include <iostream>
#include <vector>
#include <future>

using namespace std;

// Funkcja pomocnicza do porównywania dwóch wektorów
bool compareVectors(const vector<int>& a, const vector<int>& b) {
    if (a.size() != b.size()) return false;
    for(size_t i = 0; i < a.size(); ++i){
        if(a[i] != b[i])
            return false;
    }
    return true;
}

int main(){

// Test 10: Graf z odizolowanym wierzchołkiem
{
    Graph graph10(5);
    graph10.addEdge(0, 1);
    graph10.addEdge(1, 2);
    graph10.addEdge(2, 3);
    // Wierzchołek 4 jest odizolowany

    future<vector<int>> future10 = graph10.runDFSAsync(0);
    vector<int> traversal10 = future10.get();
    vector<int> expected10 = {0, 1, 2, 3};

    assert(compareVectors(traversal10, expected10) && "Test 10 nie powiódł się!");
    cout << "Test 10 przeszedł pomyślnie.\n";
}

return 0;
}