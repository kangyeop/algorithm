#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

bool compare(int a, int b) { return a > b; }

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq;

    long long sum = 0;
    sort(works.begin(), works.end(), compare);

    for (auto i : works) {
        pq.push(i);
        sum += i;
    }

    sum -= n;

    if (sum < 0) {
        return 0;
    }

    while (n) {
        int top = pq.top();
        pq.pop();
        top--;
        n--;
        pq.push(top);
    }

    while (!pq.empty()) {
        long long top = pq.top();
        pq.pop();
        answer += (top * top);
    }

    return answer;
}