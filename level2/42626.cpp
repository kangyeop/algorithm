#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> que;
    int answer = 0;
    for (auto i : scoville) {
        que.push(i);
    }
    while (!que.empty() && que.top() < K) {
        int top = que.top();
        que.pop();
        if (que.empty()) {
            return -1;
        }
        int next = que.top();
        que.pop();
        int newNum = top + (next * 2);
        que.push(newNum);
        answer++;
    }
    return answer;
}