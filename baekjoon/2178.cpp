#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m;
vector<vector<int> > arr;
vector<vector<int> > countArr;
vector<vector<int> > visit;

bool isFine(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= m) {
        return false;
    }

    if (arr[x][y] == 0) {
        return false;
    }

    if (visit[x][y]) {
        return false;
    }

    return true;
}

class Node {
  public:
    int x;
    int y;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int op1[4] = { 1, 0, -1, 0 };
    int op2[4] = { 0, 1, 0, -1 };

    cin >> n >> m;

    arr.assign(n + 1, vector<int>(m + 2, -1));
    countArr.assign(n + 1, vector<int>(m + 2, 0));
    visit.assign(n + 2, vector<int>(m + 2, 0));

    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        for (int j = 0; j < m; j++) {
            arr[i][j] = temp[j] - '0';
        }
    }

    Node start;
    start.x = 0;
    start.y = 0;

    visit[0][0] = 1;

    queue<Node> que;

    que.push(start);

    while (!que.empty()) {
        Node temp = que.front();
        que.pop();

        int x = temp.x;
        int y = temp.y;

        for (int i = 0; i < 4; i++) {
            Node newNode;
            newNode.x = x + op1[i];
            newNode.y = y + op2[i];

            if (isFine(newNode.x, newNode.y)) {
                countArr[newNode.x][newNode.y] = countArr[x][y] + 1;
                visit[newNode.x][newNode.y] = 1;
                que.push(newNode);
            }
        }
    }

    cout << countArr[n - 1][m - 1] + 1;

    return 0;
}