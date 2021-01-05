#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    queue<pair<int, int>> que;
    pair<int, int> temp;
    do {
        while (!que.empty()) {
            auto fr = que.front();
            int x = fr.first;
            int y = fr.second;
            if (board[x][y] != ' ') {
                answer++;
            }
            if (board[x][y + 1] != ' ') {
                answer++;
            }
            if (board[x + 1][y] != ' ') {
                answer++;
            }
            if (board[x + 1][y + 1] != ' ') {
                answer++;
            }
            board[x][y] = board[x][y + 1] = board[x + 1][y] = board[x + 1][y + 1] = ' ';
            que.pop();
        }
        for (int j = 0; j < n; j++) {
            for (int i = 1; i < m; i++) {
                if (board[i][j] == ' ') {
                    for (int k = i - 1; k >= 0; k--) {
                        board[k + 1][j] = board[k][j];
                        board[k][j] = ' ';
                    }
                }
            }
        }

        for (int i = 0; i < m - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                char target = board[i][j];
                if (target != ' ' && board[i + 1][j] == target
                    && board[i][j + 1] == target && board[i + 1][j + 1] == target) {
                    temp.first = i;
                    temp.second = j;
                    que.push(temp);
                }
            }
        }
    } while (!que.empty());
    return answer;
}