#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int prev   = -1;

    queue<int> que;

    typedef vector<int>::iterator it;

    for (int i = 0; i < priorities.size(); i++) {
        que.push(i);
    }

    int max = *max_element(priorities.begin(), priorities.end());

    while (!que.empty()) {
        int front = que.front();
        que.pop();
        if (priorities[front] != max) {
            que.push(front);
        } else {
            priorities[front] = -1;
            answer++;
            if (front == location) {
                break;
            }
            max = *max_element(priorities.begin(), priorities.end());
        }
    }
    return answer;
}