#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct compare {
    bool operator()(pair<double, int> a, pair<double, int> b) {
        if (a.first == b.first) {
            return a.second > b.second;
        }
        return a.first < b.first;
    }
};

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    priority_queue<pair<double, int>, vector<pair<double, int>>, compare> que;
    int finish = -1;

    for (int i = 1; i <= N; i++) {
        int total   = 0;
        int success = 0;

        for (int j = 0; j < stages.size(); j++) {
            if (stages[j] > i) {
                total++;
                success++;
            }
            if (stages[j] == i) {
                total++;
            }
        }
        if (total) {
            double percent = (double)((double)(total - success) / total);
            que.push(pair<double, int>(percent, i));
        } else {
            finish = i;
            break;
        }
    }
    while (!que.empty()) {
        pair<double, int> top = que.top();
        que.pop();
        answer.push_back(top.second);
    }

    if (finish > 0) {
        for (int i = finish; i <= N; i++) {
            answer.push_back(i);
        }
    }

    return answer;
}