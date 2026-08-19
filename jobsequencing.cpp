#include <bits/stdc++.h>
using namespace std;

struct Job {
    char id;
    int deadline, profit;
};

int main() {
    int n;
    cin >> n;

    vector<Job> jobs(n);

    for (int i = 0; i < n; i++)
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;

    sort(jobs.begin(), jobs.end(), [](Job a, Job b) {
        return a.profit > b.profit;
    });

    int maxDeadline = 0;

    for (auto job : jobs)
        maxDeadline = max(maxDeadline, job.deadline);

    vector<char> slot(maxDeadline + 1, '-');

    int totalProfit = 0;

    for (auto job : jobs) {
        for (int j = job.deadline; j >= 1; j--) {
            if (slot[j] == '-') {
                slot[j] = job.id;
                totalProfit += job.profit;
                break;
            }
        }
    }

    for (int i = 1; i <= maxDeadline; i++)
        if (slot[i] != '-')
            cout << slot[i] << " ";

    cout << "\n" << totalProfit;

    return 0;
}