#include <iostream>
#include <vector>
using namespace std;

bool DFS(int node, int parent, vector<vector<int>>& adj,
         vector<bool>& visited) {

    visited[node] = true;

    for (int neighbour : adj[node]) {

        if (!visited[neighbour]) {
            if (DFS(neighbour, node, adj, visited))
                return true;
        }

        // Visited neighbour which is not the parent
        else if (neighbour != parent) {
            return true;
        }
    }

    return false;
}

bool hasCycle(int n, vector<vector<int>>& adj) {

    vector<bool> visited(n, false);

    // Check every component
    for (int i = 0; i < n; i++) {

        if (!visited[i]) {
            if (DFS(i, -1, adj, visited))
                return true;
        }
    }

    return false;
}

int main() {

    int n, edges;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> edges;

    vector<vector<int>> adj(n);

    cout << "Enter edges:\n";

    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (hasCycle(n, adj))
        cout << "Cycle exists";
    else
        cout << "No cycle";

    return 0;
}