#include <bits/stdc++.h>
using namespace std;

int matrixChainMultiplication(vector<int>& p) {
    int n = p.size() - 1;

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    // len = number of matrices in the chain
    for (int len = 2; len <= n; len++) {

        for (int i = 1; i <= n - len + 1; i++) {

            int j = i + len - 1;

            dp[i][j] = INT_MAX;

            // Try every possible split
            for (int k = i; k < j; k++) {

                int cost = dp[i][k]
                         + dp[k + 1][j]
                         + p[i - 1] * p[k] * p[j];

                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    return dp[1][n];
}

int main() {
    int n;

    cout << "Enter number of matrices: ";
    cin >> n;

    vector<int> p(n + 1);

    cout << "Enter dimensions: ";
    for (int i = 0; i <= n; i++) {
        cin >> p[i];
    }

    cout << "Minimum number of scalar multiplications: "
         << matrixChainMultiplication(p);

    return 0;
}