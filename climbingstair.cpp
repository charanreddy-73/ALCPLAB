#include <bits/stdc++.h>
using namespace std;

int climbStairs(int n) {
    vector<int> dp(n + 1);

    dp[0] = 1;

    if (n >= 1)
        dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    int n;

    cout << "Enter number of steps: ";
    cin >> n;

    cout << "Number of ways: " << climbStairs(n);

    return 0;
}