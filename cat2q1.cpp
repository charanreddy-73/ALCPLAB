#include <bits/stdc++.h>
using namespace std;

int minAddToMakeValid(string s) {

    stack<char> st;
    int ans = 0;

    for (char ch : s) {

        if (ch == '(') {
            st.push(ch);
        }
        else {

            if (!st.empty())
                st.pop();
            else
                ans++;
        }
    }

    return ans + st.size();
}

int main() {

    string s = "())";

    cout << minAddToMakeValid(s);

    return 0;
}