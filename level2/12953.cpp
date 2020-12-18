#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int GCD(int a, int b) {
    if (a % b) {
        return GCD(b, a % b);
    }
    return b;
}

int LCM(int a, int b) { return a * b / GCD(a, b); }

int solution(vector<int> arr) {
    int answer = 0;
    sort(arr.begin(), arr.end());
    int prev = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        prev = prev > arr[i] ? LCM(arr[i], prev) : LCM(prev, arr[i]);
    }
    return prev;
}