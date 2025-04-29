#include "Graph.h"
#include "compareVectors.h"
#include <cassert>
#include <iostream>
#include <vector>
#include <future>

using namespace std;

int main(){

// Test 5: Graf niespójny
{
    Graph graph5(6);
    // Komponent 1
    graph5.addEdge(0, 1);
    graph5.addEdge(0, 2);
    // Komponent 2
    graph5.addEdge(3, 4);
    graph5.addEdge(4, 5);
    future<vector<int>> future5 = graph5.runDFSAsync(0);
    vector<int> traversal5 = future5.get();
    vector<int> expected5 = {0, 1, 2};
    assert(compareVectors(traversal5, expected5) && "Test 5 nie powiódł się!");
    cout << "Test 5 przeszedł pomyślnie.\n";
}

return 0;
}