#include <iostream>
#include <stack>
#include <string>
using namespace std;

int solution(string s) {
    int answer = 0;
    int sIndex = 0;

    stack<char> str;

    for (int i = 0; i < s.size(); i++) {
        if (str.empty()) {
            str.push(s[i]);
            continue;
        }
        char top = str.top();
        if (top == s[i]) {
            str.pop();
            continue;
        }
        str.push(s[i]);
    }

    return str.empty() ? 1 : 0;
}