#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int         answer = 0;
    vector<int> arr;
    arr.assign(n + 2, 1);
    for (int i = 2; i <= n; i++) {
        if (arr[i] == 0)
            continue;

        for (int j = i * 2; j <= n; j += i) {
            arr[j] = 0;
        }
    }

    for (int i = 2; i <= n; i++) {
        if (arr[i] != 0)
            answer++;
    }

    return answer;
}