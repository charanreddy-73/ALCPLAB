#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSafe(int node, int color[], vector<vector<int>>& graph,
                int n, int col) {
        for (int k = 0; k < n; k++) {
            if (graph[node][k] == 1 && color[k] == col)
                return false;
        }
        return true;
    }

    bool solve(int node, vector<vector<int>>& graph, int color[],
               int n, int m) {
        if (node == n)
            return true;

        for (int col = 1; col <= m; col++) {
            if (isSafe(node, color, graph, n, col)) {
                color[node] = col;

                if (solve(node + 1, graph, color, n, m))
                    return true;

                color[node] = 0;
            }
        }

        return false;
    }

    bool graphColoring(int n, vector<vector<int>>& edges, int m) {
        vector<vector<int>> graph(n, vector<int>(n, 0));

        for (auto &e : edges) {
            graph[e[0]][e[1]] = 1;
            graph[e[1]][e[0]] = 1;
        }

        int color[n] = {};
        return solve(0, graph, color, n, m);
    }
};