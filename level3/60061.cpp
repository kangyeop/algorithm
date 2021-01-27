#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> p;
vector<vector<int>> bo;

bool makeFineP(int x, int y) {
    if (!y)
        return true;
    if (p[x][y - 1])
        return true;
    if (x > 0 && bo[x - 1][y]) {
        return true;
    }
    if (x < p.size() && bo[x][y])
        return true;

    return false;
}

bool makeFineB(int x, int y) {
    if (y > 0 && p[x][y - 1]) {
        return true;
    }
    if (y > 0 && x < p.size() && p[x + 1][y - 1]) {
        return true;
    }
    if (x < p.size() && x > 0 && bo[x + 1][y] && bo[x - 1][y]) {
        return true;
    }

    return false;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    p.assign(n + 1, vector<int>(n + 1, 0));
    bo.assign(n + 1, vector<int>(n + 1, 0));

    for (auto frame : build_frame) {
        int x = frame[0];
        int y = frame[1];
        int a = frame[2];
        int b = frame[3];

        if (!a && b) {
            if (makeFineP(x, y)) {
                p[x][y] = 1;
            }
        }

        if (a && b) {
            if (makeFineB(x, y)) {
                bo[x][y] = 1;
            }
        }

        else if (!a && !b) {
            bool can = true;
            p[x][y] = 0;

            if (y < n && p[x][y + 1] && !makeFineP(x, y + 1))
                can = false;
            else if (y < n && bo[x][y + 1] && !makeFineB(x, y + 1))
                can = false;
            else if (x > 0 && bo[x - 1][y + 1] && y < n && !makeFineB(x - 1, y + 1))
                can = false;

            if (!can)
                p[x][y] = 1;
        }

        else if (a && !b) {
            bool can = 1;
            bo[x][y] = 0;

            if (p[x][y] && !makeFineP(x, y))
                can = false;
            else if (x < n && p[x + 1][y] && !makeFineP(x + 1, y))
                can = false;
            else if (x > 0 && bo[x - 1][y] && !makeFineB(x - 1, y))
                can = false;
            else if (x < n && bo[x + 1][y] && !makeFineB(x + 1, y))
                can = false;

            if (!can)
                bo[x][y] = 1;
        }
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (p[i][j]) {
                answer.push_back({ i, j, 0 });
            }
            if (bo[i][j]) {
                answer.push_back({ i, j, 1 });
            }
        }
    }

    return answer;
}