#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>> arr(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < m; i++) {
        arr[i][0] = -1;
    }
    for (int i = 0; i < n; i++) {
        arr[0][i] = -1;
    }

    for (auto i : puddles) {
        int x = i[0];
        int y = i[1];
        arr[x][y] = -1;
    }
    arr[1][1] = 1;
    for (int i = 1; i < m + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            if (arr[i][j] == -1) {
                continue;
            }
            int x = 0;
            int y = 0;
            if (arr[i - 1][j] != -1) {
                x = arr[i - 1][j];
            }
            if (arr[i][j - 1] != -1) {
                y = arr[i][j - 1];
            }
            arr[i][j] = (arr[i][j] + x + y) % 1000000007;
        }
    }
    return arr[m][n] % 1000000007;
}