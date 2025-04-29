#include "Graph.h"
#include "compareVectors.h"
#include <cassert>
#include <iostream>
#include <vector>
#include <future>

using namespace std;

int main(){

// Test 6: Graf pełny
{
    int n = 4;
    Graph graph6(n);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(i != j){
                graph6.addEdge(i, j);
            }
        }
    }

    future<vector<int>> future6 = graph6.runDFSAsync(0);
    vector<int> traversal6 = future6.get();
    // W grafie pełnym DFS może odwiedzać wierzchołki w dowolnej kolejności więc dla naszego programu zakładamy rosnąco alfabetycznie
    vector<int> expected6 = {0, 1, 2, 3};

    assert(compareVectors(traversal6, expected6) && "Test 6 nie powiódł się!");
    cout << "Test 6 przeszedł pomyślnie.\n";
}
return 0;
}