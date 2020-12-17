#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    long long answer = 1;
    long long prev = 1;
    for (int i = 2; i < n; i++) {
        long long temp = answer;
        answer = (answer + prev) % 1234567;
        prev = temp;
    }
    return answer;
}