#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> visit;
vector<vector<int>> arr;

void dfs(int a) {
    visit[a] = 1;
    for (auto i : arr[a]) {
        if (!visit[i]) {
            dfs(i);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    arr.assign(n, vector<int>(0, 0));
    visit.assign(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (computers[i][j]) {
                arr[i].push_back(j);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (!visit[i]) {
            dfs(i);
            answer++;
        }
    }

    return answer;
}