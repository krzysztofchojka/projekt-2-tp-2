#include "Graph.h"
#include "compareVectors.h"
#include <cassert>
#include <iostream>
#include <vector>
#include <future>

using namespace std;

int main(){

// Test 8: Graf z wieloma cyklami
{
    Graph graph8(5);
    graph8.addEdge(0, 1);
    graph8.addEdge(1, 2);
    graph8.addEdge(2, 0);
    graph8.addEdge(1, 3);
    graph8.addEdge(3, 4);
    graph8.addEdge(4, 1);

    future<vector<int>> future8 = graph8.runDFSAsync(0);
    vector<int> traversal8 = future8.get();
    vector<int> expected8 = {0, 1, 2, 3, 4};

    assert(compareVectors(traversal8, expected8) && "Test 8 nie powiódł się!");
    cout << "Test 8 przeszedł pomyślnie.\n";
}

return 0;
}