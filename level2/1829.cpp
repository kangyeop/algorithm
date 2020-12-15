#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> visit;
int sizeM;
int sizeN;

int bfs(int m, int n, vector<vector<int>> picture) {
    int background = picture[m][n];

    int count = 0;

    queue<pair<int, int>> que;
    pair<int, int> temp;
    temp.first = m;
    temp.second = n;
    visit[m][n]++;
    que.push(temp);

    while (!que.empty()) {
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        if (x + 1 < sizeM && picture[x + 1][y] == background && !visit[x + 1][y]) {
            temp.first = x + 1;
            temp.second = y;
            que.push(temp);
            visit[x + 1][y]++;
        }
        if (y + 1 < sizeN && picture[x][y + 1] == background && !visit[x][y + 1]) {
            temp.first = x;
            temp.second = y + 1;
            que.push(temp);
            visit[x][y + 1]++;
        }
        if (x > 0 && picture[x - 1][y] == background && !visit[x - 1][y]) {
            temp.first = x - 1;
            temp.second = y;
            que.push(temp);
            visit[x - 1][y]++;
        }
        if (y > 0 && picture[x][y - 1] == background && !visit[x][y - 1]) {
            temp.first = x;
            temp.second = y - 1;
            que.push(temp);
            visit[x][y - 1]++;
        }
        count++;
    }

    return count;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;

    sizeM = m;
    sizeN = n;

    visit.assign(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visit[i][j] && picture[i][j]) {
                int count = bfs(i, j, picture);
                if (max_size_of_one_area < count) {
                    max_size_of_one_area = count;
                }
                number_of_area++;
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}