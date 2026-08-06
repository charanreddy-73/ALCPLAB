#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {

    vector<int> need(256,0);
    vector<int> window(256,0);

    for(char c : t)
        need[c]++;

    int required = t.size();
    int left = 0;
    int minLen = INT_MAX;
    int start = 0;

    for(int right = 0; right < s.size(); right++) {

        window[s[right]]++;

        if(need[s[right]] > 0 &&
           window[s[right]] <= need[s[right]])
            required--;

        while(required == 0) {

            if(right-left+1 < minLen) {

                minLen = right-left+1;
                start = left;
            }

            window[s[left]]--;

            if(need[s[left]] > 0 &&
               window[s[left]] < need[s[left]])
                required++;

            left++;
        }
    }

    if(minLen == INT_MAX)
        return "";

    return s.substr(start,minLen);
}

int main() {

    string s = "ADOBECODEBANC";
    string t = "ABC";

    cout << minWindow(s,t);
}