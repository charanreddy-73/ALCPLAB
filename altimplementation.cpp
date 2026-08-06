#include <bits/stdc++.h>
using namespace std;
 
vector<int> nextGreaterElementBackToFront(vector<int> &arr) {
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> st;   // stores indices, candidates for the next element
 
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] <= arr[i]) {
            st.pop();               // discard candidates too small to matter
        }
 
        if (st.empty()) {
            result[i] = -1;
        } else {
            result[i] = arr[st.top()];   // resolved immediately
        }
 
        st.push(i);
    }
    return result;
}
 
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
 
    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
 
    vector<int> result = nextGreaterElementBackToFront(arr);
 
    cout << "Next Greater Elements: ";
    for (int x : result) cout << x << " ";
    cout << endl;
 
    return 0;
}
