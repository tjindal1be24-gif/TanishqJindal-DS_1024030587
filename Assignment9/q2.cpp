#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;
    void DFSUtil(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";
        for (int u : adj[v]) {
            if (!visited[u]) DFSUtil(u, visited);
        }
    }
public:
    Graph(int n) { V = n; adj.resize(V); }

    void addEdge(int u, int v) { adj[u].push_back(v); }

    void DFS(int start) {
        vector<bool> visited(V, false);
        DFSUtil(start, visited);
    }
};

int main() {
    int n = 5;
    Graph g(n);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);

    g.DFS(0);
}
