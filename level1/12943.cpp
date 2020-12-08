#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int       answer = 0;
    long long n      = num;
    while (answer < 500 && n != 1) {
        answer++;
        if (!(n % 2)) {
            n /= 2;
            continue;
        }
        n = n * 3 + 1;
    }
    return answer == 500 ? -1 : answer;
}