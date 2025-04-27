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

return traversal; });

    future<vector<int>> result = task.get_future();
    thread(move(task)).detach(); // Uruchomienie zadania w osobnym wątku
    return result;
}