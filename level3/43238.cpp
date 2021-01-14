#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end());

    long long last = times[times.size() - 1];
    long long size = n;

    long long answer = 0;
    long long maxTime = last * size;
    long long minTime = 1;
    long long minCount = numeric_limits<long long>::max();
    while (minTime <= maxTime) {
        long long currentTime = (maxTime + minTime) / 2;
        long long num = 0;
        for (auto i : times) {
            num += (currentTime / i);
        }

        if (num >= n) {
            maxTime = currentTime - 1;
            if (currentTime < minCount) {
                minCount = currentTime;
            }
        } else if (num < n) {
            minTime = currentTime + 1;
        }
    }
    return minCount;
}