#include <iostream>
#include <vector>

using namespace std;

int cal(int start, int end, int w) {
    int len = end - start + 1;
    int range = (w * 2) + 1;
    int cnt = 0;

    while (cnt * range < len) {
        cnt++;
    }

    return cnt;
}

int solution(int n, vector<int> stations, int w) {
    int answer = 0;
    int start = 1;
    if (stations[0] - w - 1 >= 1) {
        answer += cal(1, stations[0] - w - 1, w);
    }

    for (int i = 0; i < stations.size() - 1; i++) {
        answer += cal(stations[i] + w + 1, stations[i + 1] - w - 1, w);
    }

    if (stations[stations.size() - 1] + w + 1 <= n) {
        answer += cal(stations[stations.size() - 1] + w + 1, n, w);
    }

    return answer;
}