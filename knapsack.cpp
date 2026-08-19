#include <bits/stdc++.h>
using namespace std;

struct Item {
    int weight, value;
};

int main() {
    int n, capacity;
    cin >> n >> capacity;

    vector<Item> items(n);

    for (int i = 0; i < n; i++)
        cin >> items[i].weight >> items[i].value;

    sort(items.begin(), items.end(), [](Item a, Item b) {
        return (double)a.value / a.weight > (double)b.value / b.weight;
    });

    double profit = 0;

    for (int i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            capacity -= items[i].weight;
            profit += items[i].value;
        } else {
            profit += (double)items[i].value / items[i].weight * capacity;
            break;
        }
    }

    cout << profit;

    return 0;
}