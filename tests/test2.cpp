#include "Graph.h"
#include "compareVectors.h"
#include <cassert>
#include <iostream>
#include <vector>
#include <future>

using namespace std;

int main(){

// Test 2: Graf z cyklem
{
    Graph graph2(4);
    graph2.addEdge(0, 1);
    graph2.addEdge(0, 2);
    graph2.addEdge(1, 2);
    graph2.addEdge(2, 0);
    graph2.addEdge(2, 3);
    graph2.addEdge(3, 3);

    future<vector<int>> future2 = graph2.runDFSAsync(2);
    vector<int> traversal2 = future2.get();
    vector<int> expected2 = {2, 0, 1, 3};

    assert(compareVectors(traversal2, expected2) && "Test 2 nie powiódł się!");
    cout << "Test 2 przeszedł pomyślnie.\n";
}

return 0;
}