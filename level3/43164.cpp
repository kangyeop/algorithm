#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

map<string, vector<pair<string, bool>>> arr;
vector<vector<string>> answers;
int citySize;

void dfs(string start, vector<string> answer, int depth) {
    answer.push_back(start);
    if (depth == citySize) {
        answers.push_back(answer);
        return;
    }
    auto iter = arr.find(start);
    if (iter == arr.end()) {
        return;
    }
    for (int i = 0; i < iter->second.size(); i++) {
        if (!iter->second[i].second) {
            iter->second[i].second = true;
            dfs(iter->second[i].first, answer, depth + 1);
            iter->second[i].second = false;
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    for (auto i : tickets) {
        auto iter = arr.find(i[0]);

        if (iter != arr.end()) {
            iter->second.push_back(pair<string, bool>(i[1], false));
            continue;
        }
        vector<pair<string, bool>> temp { pair<string, bool>(i[1], false) };
        arr.insert({ i[0], temp });
    }

    citySize = tickets.size();

    dfs("ICN", vector<string> {}, 0);

    sort(answers.begin(), answers.end());

    return answers[0];
}