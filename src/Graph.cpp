#include "Graph.h"

using namespace std;

Graph::Graph(int vertices) : numVertices(vertices), adjList(vertices) {}

void Graph::addEdge(int src, int dest)
{
    if (src >= 0 && src < numVertices && dest >= 0 && dest < numVertices)
    {
        adjList[src].push_back(dest);
    }
}

void Graph::printGraph(){
    cout << "Lista sąsiedztwa grafu:" << endl;
    for (int i = 0; i < numVertices; ++i){
        cout << "Wierzchołek " << i << ": ";
        for (const auto &dest : adjList[i]){
            cout << dest << " ";
        }
        cout << endl;
    }
}

void Graph::DFS(int start)
{
    vector<bool> visited(numVertices, false);
    stack<int> stack;
    vector<int> traversal;

    stack.push(start);

    while (!stack.empty())
    {
        int vertex = stack.top();
        stack.pop();

        if (!visited[vertex])
        {
            visited[vertex] = true;
            traversal.push_back(vertex);

            // Dodaj sąsiadów na stos w odwrotnej kolejności dla poprawnego DFS
            for (auto it = adjList[vertex].rbegin(); it != adjList[vertex].rend(); ++it)
            {
                if (!visited[*it])
                {
                    stack.push(*it);
                }
            }
        }
    }

    printDFS(traversal);
}

void Graph::printDFS(const vector<int> &traversal)
{
    cout << "DFS Traversal: ";
    for (const auto &vertex : traversal)
    {
        cout << vertex << " ";
    }
    cout << endl;
}

future<vector<int>> Graph::runDFSAsync(int start)
{
// Użycie packaged_task
packaged_task<vector<int>()> task([this, start]()
{
// Sprawdzenie, czy start jest poprawnym wierzchołkiem
if (start < 0 || start >= numVertices) {
// Zwróć pustą listę dla niepoprawnego wierzchołka
return vector<int>();
}

vector<bool> visited(numVertices, false);
stack<int> stack;
vector<int> traversal;

stack.push(start);

while (!stack.empty()) {
int vertex = stack.top();
stack.pop();

if (!visited[vertex]) {
visited[vertex] = true;
traversal.push_back(vertex);

// Dodaj sąsiadów na stos w odwrotnej kolejności dla poprawnego DFS
for (auto it = adjList[vertex].rbegin(); it != adjList[vertex].rend(); ++it) {
if (!visited[*it]) {
stack.push(*it);
}
}
}
}

return traversal;
});

future<vector<int>> result = task.get_future();
thread(move(task)).detach(); // Uruchomienie zadania w osobnym wątku
return result;
}