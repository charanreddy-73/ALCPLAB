#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSafe(int v, vector<vector<int>>& graph,
                vector<int>& path, int pos, int n) {

        // Check if the previous vertex is connected to v
        if (graph[path[pos - 1]][v] == 0)
            return false;

        // Check if v is already in the path
        for (int i = 0; i < pos; i++) {
            if (path[i] == v)
                return false;
        }

        return true;
    }

    bool solve(vector<vector<int>>& graph, vector<int>& path,
               int pos, int n) {

        // All vertices have been added
        if (pos == n) {
            return graph[path[pos - 1]][path[0]] == 1;
        }

        // Try each vertex except the starting vertex (0)
        for (int v = 1; v < n; v++) {
            if (isSafe(v, graph, path, pos, n)) {
                path[pos] = v;

                if (solve(graph, path, pos + 1, n))
                    return true;

                // Backtrack
                path[pos] = -1;
            }
        }

        return false;
    }

    bool hamCycle(vector<vector<int>>& graph, int n) {
        vector<int> path(n, -1);
        path[0] = 0;

        return solve(graph, path, 1, n);
    }
};

int main() {
    int n = 5;

    vector<vector<int>> graph = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };

    Solution s;

    if (s.hamCycle(graph, n))
        cout << "Hamiltonian Cycle exists";
    else
        cout << "No Hamiltonian Cycle";

    return 0;
}