#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct compare {
    bool operator()(vector<int> a, vector<int> b) {
        return a.size() > b.size();
    }
};

vector<int> solution(string s) {
    priority_queue<vector<int>, vector<vector<int>>, compare> que;

    s = s.substr(1, s.size() - 2);

    bool check = false;

    vector<int> temp;
    string tempString = "";

    for (auto i : s) {
        if (i == '{') {
            check = true;
            continue;
        }
        if (i == '}') {
            temp.push_back(stoi(tempString));
            tempString = "";
            check = false;
            que.push(temp);
            temp.clear();
            continue;
        }
        if (!check) {
            continue;
        }
        if (i == ',') {
            temp.push_back(stoi(tempString));
            tempString = "";
            continue;
        }
        tempString += i;
    }

    vector<int> answer;

    while (!que.empty()) {
        auto arr = que.top();
        for (auto i : arr) {
            auto iter = find(answer.begin(), answer.end(), i);
            if (iter == answer.end()) {
                answer.push_back(i);
            }
        }
        que.pop();
    }

    return answer;
}