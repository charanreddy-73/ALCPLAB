#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// BFS Traversal
void BFS(int start, vector<vector<int>>& adj, int n) {
    vector<bool> visited(n, false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    cout << "BFS: ";

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int neighbour : adj[node]) {
            if (!visited[neighbour]) {
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }

    cout << endl;
}

// DFS Traversal
void DFS(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbour : adj[node]) {
        if (!visited[neighbour]) {
            DFS(neighbour, adj, visited);
        }
    }
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
        adj[v].push_back(u);   // Remove this for directed graph
    }

    int start;
    cout << "Enter starting vertex: ";
    cin >> start;

    // BFS
    BFS(start, adj, n);

    // DFS
    vector<bool> visited(n, false);

    cout << "DFS: ";
    DFS(start, adj, visited);

    return 0;
}