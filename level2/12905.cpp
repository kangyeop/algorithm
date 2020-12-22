#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int>> board) {
    int answer = 1234;
    vector<vector<int>> arr;
    int n = board.size() + 1;
    int m = board[0].size() + 1;
    arr.assign(n, vector<int>(m, 0));

    int max = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (board[i - 1][j - 1]) {
                arr[i][j] = min(arr[i - 1][j], min(arr[i][j - 1], arr[i - 1][j - 1])) + 1;
                if (arr[i][j] > max) {
                    max = arr[i][j];
                }
            }
        }
    }
    return max * max;
}