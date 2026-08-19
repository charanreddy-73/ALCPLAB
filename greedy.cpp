#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;

    sort(a.begin(), a.end(), [](auto x, auto y) {
        return x.second < y.second;
    });

    int count = 1;
    int lastEnd = a[0].second;

    for (int i = 1; i < n; i++) {
        if (a[i].first >= lastEnd) {
            count++;
            lastEnd = a[i].second;
        }
    }

    cout << count;

    return 0;
}