#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<int>> arr(n + 1, vector<int>(n + 1, -1));
    for (auto i : results) {
        int a = i[0];
        int b = i[1];
        arr[a][b] = 1;
        arr[b][a] = 0;
    }

    for (int i = 1; i < n + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            for (int k = 1; k < n + 1; k++) {
                if (arr[j][k] == -1) {
                    if (arr[i][j] == 1 && arr[k][i] == 1) {
                        arr[k][j] = 1;
                        arr[j][k] = 0;
                    }
                    if (arr[i][j] == 0 && arr[k][i] == 0) {
                        arr[k][j] = 0;
                        arr[j][k] = 1;
                    }
                }
            }
        }
    }

    for (int i = 1; i < n + 1; i++) {
        bool has_INF = false;
        for (int j = 1; j < n + 1; j++) {
            if (i != j && arr[i][j] == -1) {
                has_INF = true;
                break;
            }
        }
        answer += has_INF ? 0 : 1;
    }
    return answer;
}