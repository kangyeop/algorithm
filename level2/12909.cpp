#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool solution(string s) {
    bool answer = true;
    stack<char> st;
    for (auto i : s) {
        if (i == ')') {
            if (!st.empty() && st.top() == '(') {
                st.pop();
                continue;
            }
        }
        st.push(i);
    }
    if (st.empty()) {
        return true;
    }
    return false;
}