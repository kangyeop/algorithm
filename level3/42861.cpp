#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> costs) {
    // int answer = 0;
    vector<vector<int>> arr;
    arr.assign(n, vector<int>(n, 0));
    for (auto i : costs) {
        int x = i[0];
        int y = i[1];
        int cost = i[2];
        arr[x][y] = cost;
        arr[y][x] = cost;
    }

    vector<int> totalCost;
    vector<int> visit;
    totalCost.assign(n, numeric_limits<int>::max());
    totalCost[0] = 0;
    visit.assign(n, 0);

    while (find(visit.begin(), visit.end(), 0) != visit.end()) {
        int minNum = numeric_limits<int>::max();
        int index = -1;
        for (int i = 0; i < n; i++) {
            if (!visit[i]) {
                if (totalCost[i] < minNum) {
                    minNum = totalCost[i];
                    index = i;
                }
            }
        }
        visit[index] = 1;
        for (int i = 0; i < n; i++) {
            if (arr[index][i] && !visit[i]) {
                int temp = min(totalCost[i], arr[index][i]);
                totalCost[i] = temp;
            }
        }
    }

    int sum = 0;
    for (auto i : totalCost) {
        sum += i;
    }

    return sum;
}
