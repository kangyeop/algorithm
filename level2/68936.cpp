#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> testArr;
vector<int> answer;

int isSame(int x, int y, int n, int m) {
    int num = -1;
    for (int i = x; i < n; i++) {
        for (int j = y; j < m; j++) {
            if (num == -1) {
                num = testArr[i][j];
                continue;
            }
            if (num != testArr[i][j]) {
                return -1;
            }
        }
    }
    answer[num]++;
    return num;
}

vector<int> solution(vector<vector<int>> arr) {
    answer.assign(2, 0);
    testArr = arr;
    int n = arr.size();

    queue<vector<int>> range;
    int m = n / 2;
    vector<int> temp = { 0, 0, m, m };
    range.push(temp);
    temp = { 0, m, m, n };
    range.push(temp);
    temp = { m, 0, n, m };
    range.push(temp);
    temp = { m, m, n, n };
    range.push(temp);

    while (!range.empty()) {
        vector<int> top = range.front();
        range.pop();
        int res = isSame(top[0], top[1], top[2], top[3]);
        if (res == -1) {
            temp = { top[0], top[1], (top[0] + top[2]) / 2, (top[1] + top[3]) / 2 };
            range.push(temp);
            temp = { (top[0] + top[2]) / 2, top[1], top[2], (top[1] + top[3]) / 2 };
            range.push(temp);
            temp = { top[0], (top[1] + top[3]) / 2, (top[0] + top[2]) / 2, top[3] };
            range.push(temp);
            temp = { (top[0] + top[2]) / 2, (top[1] + top[3]) / 2, top[2], top[3] };
            range.push(temp);
        }
    }

    if (!answer[0]) {
        answer[1] = 1;
    }
    if (!answer[1]) {
        answer[0] = 1;
    }

    return answer;
}