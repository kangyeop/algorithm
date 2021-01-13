#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

bool comp(vector<int> a, vector<int> b) { return a[0] < b[0]; }

struct compare {
    bool operator()(vector<int> a, vector<int> b) { return a[1] > b[1]; }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    sort(jobs.begin(), jobs.end(), comp);

    priority_queue<vector<int>, vector<vector<int>>, compare> pique;

    int count = 0;
    int current = 0;
    int size = jobs.size();

    while (count < size || !pique.empty()) {
        for (int i = count; i < jobs.size(); i++) {
            if (jobs[i][0] <= current) {
                pique.push(jobs[i]);
                count++;
                continue;
            }
            break;
        }

        if (pique.empty() && count < size) {
            current++;
            continue
        }

        if (!pique.empty()) {
            vector<int> top = pique.top();
            pique.pop();
            current += top[1];
            answer += (current - top[0]);
        }
    }

    return answer / size;
}
