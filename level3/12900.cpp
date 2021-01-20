#include <iostream>
#include <string>
#include <vector>

using namespace std;

int MOD = 1000000007;

int solution(int n) {
    vector<int> arr;
    arr.assign(n + 1, 0);
    arr[0] = 1;
    arr[1] = 1;
    for (int i = 2; i <= n; i++) {
        arr[i] = (arr[i - 2] + arr[i - 1]) % MOD;
    }
    int answer = arr[n];
    return answer;
}