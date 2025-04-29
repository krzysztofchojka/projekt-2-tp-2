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

// Test 9: Graf skierowany
{
    Graph graph9(4);
    graph9.addEdge(0, 1);
    graph9.addEdge(0, 2);
    graph9.addEdge(1, 2);
    graph9.addEdge(2, 3);

    future<vector<int>> future9 = graph9.runDFSAsync(0);
    vector<int> traversal9 = future9.get();
    vector<int> expected9 = {0, 1, 2, 3};

    assert(compareVectors(traversal9, expected9) && "Test 9 nie powiódł się!");
    cout << "Test 9 przeszedł pomyślnie.\n";
}

return 0;
}