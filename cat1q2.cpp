#include <bits/stdc++.h>
using namespace std;

int precedence(char ch) {

    if (ch == '^')
        return 3;

    if (ch == '*' || ch == '/')
        return 2;

    if (ch == '+' || ch == '-')
        return 1;

    return -1;
}

string infixToPostfix(string s) {

    stack<char> st;
    string ans = "";

    for (char ch : s) {

        if (isalnum(ch)) {
            ans += ch;
        }

        else if (ch == '(') {
            st.push(ch);
        }

        else if (ch == ')') {

            while (!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }

            st.pop();
        }

        else {

            while (!st.empty() &&
                   precedence(st.top()) >= precedence(ch)) {

                ans += st.top();
                st.pop();
            }

            st.push(ch);
        }
    }

    while (!st.empty()) {

        ans += st.top();
        st.pop();
    }

    return ans;
}

int main() {

    string s = "(A+B)*C";

    cout << infixToPostfix(s);

    return 0;
}