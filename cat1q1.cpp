#include <bits/stdc++.h>
using namespace std;

int evaluatePostfix(string s) {
    stack<int> st;

    for (char ch : s) {

        if (isdigit(ch)) {
            st.push(ch - '0');
        }
        else {

            int b = st.top();
            st.pop();

            int a = st.top();
            st.pop();

            if (ch == '+')
                st.push(a + b);

            else if (ch == '-')
                st.push(a - b);

            else if (ch == '*')
                st.push(a * b);

            else if (ch == '/')
                st.push(a / b);
        }
    }

    return st.top();
}

int main() {

    string s = "23+4*";

    cout << evaluatePostfix(s);

    return 0;
}