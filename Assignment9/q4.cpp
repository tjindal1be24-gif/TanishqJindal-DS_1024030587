#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minDistance(vector<int>& dist, vector<bool>& sptSet, int V) {
    int minVal = INT_MAX, minIndex = -1;
    for (int v = 0; v < V; v++)
        if (!sptSet[v] && dist[v] <= minVal) { minVal = dist[v]; minIndex = v; }
    return minIndex;
}

void dijkstra(vector<vector<int>>& graph, int src) {
    int V = graph.size();
    vector<int> dist(V, INT_MAX);
    vector<bool> sptSet(V, false);
    dist[src] = 0;

    for (int count = 0; count < V-1; count++) {
        int u = minDistance(dist, sptSet, V);
        sptSet[u] = true;
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    for (int i = 0; i < V; i++)
        cout << "Vertex " << i << " : " << dist[i] << endl;
}

int main() {
    vector<vector<int>> graph = {
        {0, 10, 0, 0, 0, 0, 0, 8, 0},
        {10, 0, 10, 30, 0, 0, 0, 0, 0},
        {0, 10, 0, 0, 0, 0, 0, 0, 0},
        {0, 30, 0, 0, 2, 0, 0, 0, 0},
        {0, 0, 0, 2, 0, 3, 0, 0, 0},
        {0, 0, 0, 0, 3, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 0, 1},
        {8, 0, 0, 0, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 1, 1, 0}
    };
    dijkstra(graph, 0);
}
