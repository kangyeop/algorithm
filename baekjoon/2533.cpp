#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> child;
vector<int> visit;
vector<vector<int>> dp;

void dfs(int idx) {
    visit[idx] = 1;
    dp[idx][0] = 0;
    dp[idx][1] = 1;
    for (int i = 0; i < child[idx].size(); i++) {
        if (visit[child[idx][i]])
            continue;
        dfs(child[idx][i]);
        dp[idx][0] += dp[child[idx][i]][1];
        dp[idx][1] += min(dp[child[idx][i]][1], dp[child[idx][i]][0]);
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    child.assign(n + 1, vector<int>(0, 0));
    visit.assign(n + 1, 0);
    dp.assign(n + 1, vector<int>(2, 0));

    for (int i = 0; i < (n - 1); i++) {
        int p, c;
        cin >> p >> c;
        child[p].push_back(c);
        child[c].push_back(p);
    }

    dfs(1);

    cout << min(dp[1][1], dp[1][0]) << endl;

    return 0;
}