#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int solution(int N, vector<vector<int>> road, int K) {
    int answer = 0;
    vector<vector<int>> arr(N + 1, vector<int>(N + 1, 0));
    vector<int> dp(N + 1, numeric_limits<int>::max());
    vector<int> visit(N + 1, 0);

    for (auto i : road) {
        int x = i[0];
        int y = i[1];
        int cost = i[2];

        arr[x][y] = arr[x][y] ? min(cost, arr[x][y]) : cost;
        arr[y][x] = arr[y][x] ? min(cost, arr[y][x]) : cost;
    }

    visit[0] = 1;
    dp[1] = 0;
    int i = 1;

    while (true) {
        visit[i] = 1;

        for (int j = 1; j <= N; j++) {
            if (arr[i][j]) {
                dp[j] = min(dp[j], dp[i] + arr[i][j]);
            }
        }

        int minNum = numeric_limits<int>::max();
        bool finish = true;
        for (int k = 1; k <= N; k++) {
            if (visit[k]) {
                continue;
            }
            minNum = min(minNum, dp[k]);
            if (minNum == dp[k]) {
                i = k;
                finish = false;
            }
        }
        if (finish) {
            break;
        }
    }

    for (int i = 1; i <= N; i++) {
        if (dp[i] <= K) {
            answer++;
        }
    }

    return answer;
}