#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer;
    int index = 0;
    for (int i = 0; i < number.size() - k; i++) {
        int max = -1;
        // 고른 시점으로 부터 k 개 확인
        // 현 시점에서 k개를 확인하면 남은 number size - k 개는 뒤에서 뽑을 수 있음
        for (int j = index; j <= i + k; j++) {
            int temp = number[j] - '0';
            if (temp > max) {
                max = temp;
                index = j + 1;
            }
        }
        answer += to_string(max);
    }
    return answer;
}