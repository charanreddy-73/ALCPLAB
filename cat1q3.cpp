#include <bits/stdc++.h>
using namespace std;

int calculate(string s) {

    stack<int> st;

    int result = 0;
    int number = 0;
    int sign = 1;

    for (char ch : s) {

        if (isdigit(ch)) {

            number = number * 10 + (ch - '0');
        }

        else if (ch == '+') {

            result += sign * number;
            number = 0;
            sign = 1;
        }

        else if (ch == '-') {

            result += sign * number;
            number = 0;
            sign = -1;
        }

        else if (ch == '(') {

            st.push(result);
            st.push(sign);

            result = 0;
            sign = 1;
        }

        else if (ch == ')') {

            result += sign * number;
            number = 0;

            result *= st.top();
            st.pop();

            result += st.top();
            st.pop();
        }
    }

    result += sign * number;

    return result;
}

int main() {

    string s = "(1+(4+5+2)-3)+(6+8)";

    cout << calculate(s);

    return 0;
}