#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int>> land) {
    int answer = 0;

    vector<vector<int>> arr;
    int n = land.size();
    int m = land[0].size();
    arr.assign(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int max = 0;
            for (int k = 1; k <= m; k++) {
                if (j == k) {
                    continue;
                }
                if (arr[i - 1][k] > max) {
                    max = arr[i - 1][k];
                }
            }
            arr[i][j] = max + land[i - 1][j - 1];
        }
    }

    answer = *max_element(arr[n].begin(), arr[n].end());

    return answer;
}