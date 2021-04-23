#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Node {
  public:
    int x;
    int y;
    int num;
};

vector<int> xNum = { 0, 0, 1, -1 };
vector<int> yNum = { -1, 1, 0, 0 };
int n, m;

int main() {
    cin >> n >> m;

    Node start;

    vector<vector<int>> water(n, vector<int>(m, 9999));
    vector<vector<int>> visit(n, vector<int>(m, 0));

    vector<string> arr;
    queue<Node> wq;

    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        for (int j = 0; j < temp.size(); j++) {
            if (temp[j] == 'S') {
                start.x = i;
                start.y = j;
                start.num = 0;
            } else if (temp[j] == '*') {
                Node t;
                t.x = i;
                t.y = j;
                t.num = 0;
                wq.push(t);
                visit[i][j] = 1;
            }
        }
        arr.push_back(temp);
    }

    while (!wq.empty()) {
        Node fr = wq.front();
        int i = fr.x;
        int j = fr.y;
        int num = fr.num;
        wq.pop();
        for (int k = 0; k < 4; k++) {
            if ((i + xNum[k]) < n && (j + yNum[k]) < m && (i + xNum[k]) >= 0
                && (j + yNum[k]) >= 0) {
                if (arr[i + xNum[k]][j + yNum[k]] == '.'
                    && visit[i + xNum[k]][j + yNum[k]] == 0) {
                    visit[i + xNum[k]][j + yNum[k]] = 1;
                    water[i + xNum[k]][j + yNum[k]] = num + 1;
                    Node tWater;
                    tWater.x = i + xNum[k];
                    tWater.y = j + yNum[k];
                    tWater.num = num + 1;
                    wq.push(tWater);
                }
            }
        }
    }

    visit.clear();
    visit.assign(n, vector<int>(m, 0));
    visit[start.x][start.y] = 1;
    queue<Node> qu;
    qu.push(start);

    while (!qu.empty()) {
        Node fr = qu.front();
        int i = fr.x;
        int j = fr.y;
        int num = fr.num;
        if (arr[i][j] == 'D') {
            cout << num << "endl";
            return 0;
        }
        qu.pop();

        for (int k = 0; k < 4; k++) {
            if ((i + xNum[k]) < n && (j + yNum[k]) < m && (i + xNum[k]) >= 0
                && (j + yNum[k]) >= 0) {

                if (visit[i + xNum[k]][j + yNum[k]] != 0) {
                    continue;
                }

                if (arr[i + xNum[k]][j + yNum[k]] != '.'
                    && arr[i + xNum[k]][j + yNum[k]] != 'D') {
                    continue;
                }

                if (arr[i + xNum[k]][j + yNum[k]] == 'D') {
                    cout << num + 1 << endl;
                    return 0;
                }

                if (water[i + xNum[k]][j + yNum[k]] > (num + 1)) {
                    visit[i + xNum[k]][j + yNum[k]] = 1;
                    Node temp;
                    temp.x = i + xNum[k];
                    temp.y = j + yNum[k];
                    temp.num = num + 1;
                    qu.push(temp);
                }
            }
        }
    }

    cout << "KAKTUS" << endl;

    return 0;
}