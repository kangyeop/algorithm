#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    for (auto i : s) {
        char start = 'a';
        if(i == ' '){
            answer += " ";
            continue;
        }
        if ('A' <= i && i <= 'Z') {
            start = 'A';
        }
        answer += start + (i + n - start) % 26;
    }
    return answer;
}