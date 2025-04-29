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

// Test 1: Graf prosty
{
    Graph graph1(5);
    graph1.addEdge(0, 1);
    graph1.addEdge(0, 2);
    graph1.addEdge(1, 3);
    graph1.addEdge(1, 4);

    future<vector<int>> future1 = graph1.runDFSAsync(0);
    vector<int> traversal1 = future1.get();
    vector<int> expected1 = {0, 1, 3, 4, 2};

    assert(compareVectors(traversal1, expected1) && "Test 1 nie powiódł się!");
    cout << "Test 1 przeszedł pomyślnie.\n";
}
}