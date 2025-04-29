#include "Graph.h"
#include "compareVectors.h"
#include <cassert>
#include <iostream>
#include <vector>
#include <future>

using namespace std;

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