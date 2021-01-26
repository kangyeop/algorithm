#include <string>
#include <vector>

using namespace std;

vector<vector<int>> check;
int tSize;
int answer = 0;

bool isTrue(int col, int row) {
    int n = tSize;
    //가로
    for (int i = 0; i < n; i++) {
        if (check[col][i] == true)
            return false;
    }

    //세로
    for (int i = 0; i < n; i++) {
        if (check[i][row] == true)
            return false;
    }

    //우측 상방 대각
    for (int i = col, j = row; i >= 0 && j < n; i--, j++) {
        if (check[i][j] == true)
            return false;
    }

    //우측 하방 대각
    for (int i = col, j = row; i < n && j < n; i++, j++) {
        if (check[i][j] == true)
            return false;
    }

    //좌측 상방 대각
    for (int i = col, j = row; i >= 0 && j >= 0; i--, j--) {
        if (check[i][j] == true)
            return false;
    }

    //좌측 하방 대각
    for (int i = col, j = row; i < n && j >= 0; i++, j--) {
        if (check[i][j] == true)
            return false;
    }
    return true;
}

void dfs(int col, int depth) {
    if (depth == tSize) {
        answer++;
        return;
    }
    for (int i = 0; i < tSize; i++) {
        if (isTrue(col, i)) {
            check[col][i] = 1;
            dfs(col + 1, depth + 1);
            check[col][i] = 0;
        }
    }
}

int solution(int n) {
    check.assign(n, vector<int>(n, 0));
    tSize = n;
    dfs(0, 0);
    return answer;
}