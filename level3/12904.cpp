#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int n = s.size();

    vector<vector<int>> arr;
    arr.assign(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        arr[i][i] = 1;
        answer = 1;
    }

    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            arr[i][i + 1] = 1;
            answer = 2;
        }
    }

    for (int i = 3; i <= n; i++) {
        for (int j = 0; j < n - i + 1; j++) {
            int k = j + i - 1;
            if (s[j] == s[k] && arr[j + 1][k - 1]) {
                arr[j][k] = 1;
                answer = max(answer, i);
            }
        }
    }

    return answer;
}