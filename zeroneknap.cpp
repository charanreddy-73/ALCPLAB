class Solution {
public:
    int knapsack(int W, vector<int>& weight, vector<int>& value, int n) {

        vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

        for (int i = 1; i <= n; i++) {

            for (int w = 1; w <= W; w++) {

                // Don't take the item
                dp[i][w] = dp[i - 1][w];

                // Take the item if it fits
                if (weight[i - 1] <= w) {
                    dp[i][w] = max(
                        dp[i][w],
                        value[i - 1] + dp[i - 1][w - weight[i - 1]]
                    );
                }
            }
        }

        return dp[n][W];
    }
};