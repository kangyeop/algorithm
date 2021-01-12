#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    vector<vector<int>> arr;
    arr.assign(n, vector<int>(0, 0));
    for (auto i : edge) {
        int x = i[0] - 1;
        int y = i[1] - 1;
        arr[x].push_back(y);
        arr[y].push_back(x);
    }

    vector<int> distance;
    vector<int> visit;
    queue<int> que;

    distance.assign(n, numeric_limits<int>::max());
    visit.assign(n, 0);

    que.push(0);
    distance[0] = 0;
    visit[0] = 1;

    while (!que.empty()) {
        int front = que.front();
        que.pop();
        for (auto i : arr[front]) {
            if (!visit[i]) {
                int num = min(distance[front] + 1, distance[i]);
                distance[i] = num;
                if (num == (distance[front] + 1)) {
                    visit[i] = 1;
                    que.push(i);
                }
            }
        }
    }

    int maxNum = *max_element(distance.begin(), distance.end());
    int answer = count(distance.begin(), distance.end(), maxNum);

    return answer;
}