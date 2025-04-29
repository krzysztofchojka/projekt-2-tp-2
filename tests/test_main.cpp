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

// Test 4: Graf z jednym wierzchołkiem
{
    Graph graph4(1);
    future<vector<int>> future4 = graph4.runDFSAsync(0);
    vector<int> traversal4 = future4.get();
    vector<int> expected4 = {0};
    assert(compareVectors(traversal4, expected4) && "Test 4 nie powiódł się!");
    cout << "Test 4 przeszedł pomyślnie.\n";
}

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

// Test 10: Graf z odizolowanym wierzchołkiem
{
    Graph graph10(5);
    graph10.addEdge(0, 1);
    graph10.addEdge(1, 2);
    graph10.addEdge(2, 3);
    // Wierzchołek 4 jest odizolowany

    future<vector<int>> future10 = graph10.runDFSAsync(0);
    vector<int> traversal10 = future10.get();
    vector<int> expected10 = {0, 1, 2, 3};

    assert(compareVectors(traversal10, expected10) && "Test 10 nie powiódł się!");
    cout << "Test 10 przeszedł pomyślnie.\n";
}

cout << "Wszystkie testy zakończyły się sukcesem.\n";
return 0;
}