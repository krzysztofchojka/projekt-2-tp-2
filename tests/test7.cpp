#include "Graph.h"
#include "compareVectors.h"
#include <cassert>
#include <iostream>
#include <vector>
#include <future>

using namespace std;

int main(){

// Test 7: Graf drzewiasty
{
    Graph graph7(7);
    graph7.addEdge(0, 1);
    graph7.addEdge(0, 2);
    graph7.addEdge(1, 3);
    graph7.addEdge(1, 4);
    graph7.addEdge(2, 5);
    graph7.addEdge(2, 6);

    future<vector<int>> future7 = graph7.runDFSAsync(0);
    vector<int> traversal7 = future7.get();
    vector<int> expected7 = {0, 1, 3, 4, 2, 5, 6};

    assert(compareVectors(traversal7, expected7) && "Test 7 nie powiódł się!");
    cout << "Test 7 przeszedł pomyślnie.\n";
}
return 0;
}