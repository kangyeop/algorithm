#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int    index  = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            answer += s[i];
            index = i + 1;
            continue;
        }
        if (!((i - index) % 2)) {
            answer += toupper(s[i]);
        } else {
            answer += tolower(s[i]);
        }
    }
    return answer;
}