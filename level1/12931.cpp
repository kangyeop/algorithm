#include <iostream>

using namespace std;
int solution(int n) {
    int    answer = 0;
    string num    = to_string(n);
    for (int i = 0; i < num.size(); i++) {
        int s = num[i] - '0';
        answer += s;
    }
    return answer;
}