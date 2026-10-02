#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;

    for (string s : strs) {
        string key = s;
        sort(key.begin(), key.end());

        mp[key].push_back(s);
    }

    vector<vector<string>> result;

    for (auto& pair : mp) {
        result.push_back(pair.second);
    }

    return result;
}

int main() {
    vector<string> strs = {
        "eat", "tea", "tan", "ate", "nat", "bat"
    };

    vector<vector<string>> result = groupAnagrams(strs);

    for (auto& group : result) {
        cout << "[";
        for (int i = 0; i < group.size(); i++) {
            cout << group[i];
            if (i != group.size() - 1)
                cout << ", ";
        }
        cout << "]\n";
    }

    return 0;
}