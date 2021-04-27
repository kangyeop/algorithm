#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#define INF 987654321

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> arr(n + 50, vector<pair<int, int>> {});

    for (int i = 0; i < m; i++) {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        arr[t1].push_back(make_pair(t2, t3));
        arr[t2].push_back(make_pair(t1, t3));
    }

    int x, y;
    cin >> x >> y;

    vector<int> dp1(n + 50, INF);
    vector<int> dp2(n + 50, INF);
    vector<int> dp3(n + 50, INF);

    priority_queue<pair<int, int>> pq;

    pq.push(make_pair(0, 1));
    dp1[1] = 0;
    while (!pq.empty()) {
        int idx = pq.top().second;
        int value = -pq.top().first;
        pq.pop();

        for (int j = 0; j < arr[idx].size(); j++) {
            int next = arr[idx][j].first;
            int nextValue = arr[idx][j].second;
            if (1 == next)
                continue;
            if (dp1[next] > nextValue + value) {
                dp1[next] = nextValue + value;
                pq.push(make_pair(-dp1[next], next));
            }
        }
    }

    pq.push(make_pair(0, x));

    while (!pq.empty()) {
        int idx = pq.top().second;
        int value = -pq.top().first;
        pq.pop();

        for (int j = 0; j < arr[idx].size(); j++) {
            int next = arr[idx][j].first;
            int nextValue = arr[idx][j].second;
            if (x == next)
                continue;
            if (dp2[next] > nextValue + value) {
                dp2[next] = nextValue + value;
                pq.push(make_pair(-dp2[next], next));
            }
        }
    }

    pq.push(make_pair(0, y));
    dp3[y] = 0;
    while (!pq.empty()) {
        int idx = pq.top().second;
        int value = -pq.top().first;
        pq.pop();

        for (int j = 0; j < arr[idx].size(); j++) {
            int next = arr[idx][j].first;
            int nextValue = arr[idx][j].second;
            if (y == next)
                continue;
            if (dp3[next] > nextValue + value) {
                dp3[next] = nextValue + value;
                pq.push(make_pair(-dp3[next], next));
            }
        }
    }

    int t1, t2;
    bool flag1 = true, flag2 = true;

    if (dp1[x] == INF || dp2[y] == INF || dp3[n] == INF) {
        t1 = INF;
        flag1 = false;
    }

    if (dp1[y] == INF || dp3[x] == INF || dp2[n] == INF) {
        t2 = INF;
        flag2 = false;
    }

    if (flag1) {
        t1 = dp1[x] + dp2[y] + dp3[n];
    }
    if (flag2) {
        t2 = dp1[y] + dp3[x] + dp2[n];
    }

    if (t1 == INF && t2 == INF) {
        cout << -1 << endl;
    } else {
        int answer = min(t1, t2);
        cout << answer << endl;
    }

    return 0;
}
