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


// Test 4: Graf z jednym wierzchołkiem
{
    Graph graph4(1);
    future<vector<int>> future4 = graph4.runDFSAsync(0);
    vector<int> traversal4 = future4.get();
    vector<int> expected4 = {0};
    assert(compareVectors(traversal4, expected4) && "Test 4 nie powiódł się!");
    cout << "Test 4 przeszedł pomyślnie.\n";
}

return 0;
}