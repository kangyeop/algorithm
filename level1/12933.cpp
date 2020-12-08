#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
    string      s = to_string(n);
    vector<int> arr;
    for (int i = 0; i < s.size(); i++) {
        arr.push_back(s[i] - '0');
    }
    sort(arr.begin(), arr.end());
    string sAnswer = "";
    for (int i = arr.size() - 1; i >= 0; i--) {
        sAnswer += to_string(arr[i]);
    }
    long long answer = stol(sAnswer);
    return answer;
}