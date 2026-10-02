#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;

    cout << "Enter number of terms: ";
    cin >> n;

    vector<int> dp(n);

    dp[0] = 0;

    if (n > 1)
        dp[1] = 1;

    for (int i = 2; i < n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << "Fibonacci Series: ";

    for (int i = 0; i < n; i++) {
        cout << dp[i] << " ";
    }

    return 0;
}