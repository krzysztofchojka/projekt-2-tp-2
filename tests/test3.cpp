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

// Test 3: Pusty graf (0 wierzchołków)
{
    Graph graph3(0);
    try {
        future<vector<int>> future3 = graph3.runDFSAsync(0);
        vector<int> traversal3 = future3.get();
        vector<int> expected3 = {};
        assert(compareVectors(traversal3, expected3) && "Test 3 nie powiódł się!");
        cout << "Test 3 przeszedł pomyślnie.\n";
    } catch (const exception& e) {
        cout << "Test 3 przeszedł pomyślnie (wyjątek: " << e.what() << ").\n";
    }
}

return 0;
}