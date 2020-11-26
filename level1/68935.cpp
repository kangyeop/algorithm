#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int a) {
    int    answer = 0;
    string third  = "";

    while (a / 3) {
        third += to_string(a % 3);
        a = a / 3;
    }
    third += to_string(a);

    for (int i = third.size() - 1; i >= 0; i--) {
        int num = third[i] - '0';
        for (int j = 0; j < third.size() - i - 1; j++) {
            num *= 3;
        }
        answer += num;
    }

    return answer;
}