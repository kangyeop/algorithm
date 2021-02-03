#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Node {
  public:
    int x;
    int y;
    int cost;
    int dir;
};

int solution(vector<vector<int>> board) {
    queue<Node> q;
    Node start;
    start.cost = 0;
    start.x = 0;
    start.y = 0;
    start.dir = 10;

    q.push(start);

    int N = board.size();
    int mx[] = { 0, 1, 0, -1 };
    int my[] = { 1, 0, -1, 0 };

    board[0][0] = 1;

    int answer = numeric_limits<int>::max();

    while (!q.empty()) {
        Node a = q.front();
        q.pop();
        if (a.x == N - 1 && a.y == N - 1) {
            if (answer > a.cost)
                answer = a.cost;
            continue;
        }
        for (int i = 0; i < 4; i++) {
            int nx = a.x + mx[i];
            int ny = a.y + my[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= N || board[nx][ny] == 1)
                continue;

            int nc = 0;

            if (a.dir == 10 || a.dir == i)
                nc = a.cost + 100;
            else if (a.dir != i)
                nc = a.cost + 600;

            if (board[nx][ny] == 0 || board[nx][ny] >= nc) {
                board[nx][ny] = nc;
                Node p;
                p.x = nx, p.y = ny, p.cost = nc, p.dir = i;
                q.push(p);
            }
        }
    }
    return answer;
}