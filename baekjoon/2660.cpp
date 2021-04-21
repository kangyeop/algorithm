#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> arr(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 1000));

    while (true) {
        int t1, t2;
        cin >> t1 >> t2;
        if (t1 == -1 && t2 == -1) {
            break;
        }
        arr[t1][t2] = 1;
        arr[t2][t1] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (arr[i][j]) {
                dp[i][j] = 1;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j)
                continue;
            for (int k = 1; k <= n; k++) {
                if (i == k || j == k)
                    continue;
                dp[j][k] = min(dp[i][j] + dp[i][k], dp[j][k]);
            }
        }
    }

    vector<int> answer;
    int minNum = 5000;
    int minIdx = -1;

    for (int i = 1; i <= n; i++) {
        int max = -1;
        for (int j = 1; j <= n; j++) {
            if (max < dp[i][j] && dp[i][j] != 1000) {
                max = dp[i][j];
            }
        }
        if (max < minNum) {
            minNum = max;
            minIdx = i;
            answer.clear();
            answer.push_back(i);
        } else if (max == minNum) {
            answer.push_back(i);
        }
    }

    cout << minNum << " " << answer.size() << "\n";

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    cout << endl;

    return 0;
}
