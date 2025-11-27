#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

struct Edge {
    int u, v, w;
};

int findParent(int parent[], int i) {
    if (parent[i] == i) return i;
    return parent[i] = findParent(parent, parent[i]);
}

void unionSets(int parent[], int rank[], int u, int v) {
    int pu = findParent(parent, u);
    int pv = findParent(parent, v);
    if (rank[pu] < rank[pv]) parent[pu] = pv;
    else if (rank[pu] > rank[pv]) parent[pv] = pu;
    else { parent[pv] = pu; rank[pu]++; }
}

void Kruskal(int V, vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), [](Edge a, Edge b){ return a.w < b.w; });
    int parent[V], rank[V] = {0};
    for (int i = 0; i < V; i++) parent[i] = i;
    int cost = 0;
    cout << "Kruskal MST:\n";
    for (Edge e : edges) {
        if (findParent(parent, e.u) != findParent(parent, e.v)) {
            cout << e.u << " - " << e.v << " : " << e.w << endl;
            cost += e.w;
            unionSets(parent, rank, e.u, e.v);
        }
    }
    cout << "Total cost: " << cost << endl;
}

void Prim(int V, vector<vector<int>>& graph) {
    vector<int> key(V, INT_MAX), parent(V, -1);
    vector<bool> mstSet(V, false);
    key[0] = 0;

    for (int count = 0; count < V-1; count++) {
        int u = -1, minKey = INT_MAX;
        for (int v = 0; v < V; v++)
            if (!mstSet[v] && key[v] < minKey) { minKey = key[v]; u = v; }

        mstSet[u] = true;
        for (int v = 0; v < V; v++)
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                parent[v] = u;
            }
    }

    int cost = 0;
    cout << "Prim MST:\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] << " - " << i << " : " << graph[i][parent[i]] << endl;
        cost += graph[i][parent[i]];
    }
    cout << "Total cost: " << cost << endl;
}

int main() {
    int V = 5;
    vector<Edge> edges = {{0,1,2},{0,3,6},{1,2,3},{1,3,8},{1,4,5},{2,4,7},{3,4,9}};
    Kruskal(V, edges);

    vector<vector<int>> graph = {
        {0,2,0,6,0},
        {2,0,3,8,5},
        {0,3,0,0,7},
        {6,8,0,0,9},
        {0,5,7,9,0}
    };
    Prim(V, graph);
}
