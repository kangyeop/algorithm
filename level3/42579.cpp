#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) { return a.first > b.first; }

bool compare_map_value(pair<string, int> a, pair<string, int> b) {
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    unordered_map<string, vector<pair<int, int>>> arr;
    unordered_map<string, int> arr2;
    vector<pair<string, int>> arr3;
    for (int i = 0; i < genres.size(); i++) {
        pair<int, int> temp;
        temp.first = plays[i];
        temp.second = i;
        arr[genres[i]].push_back(temp);
        arr2[genres[i]] += plays[i];
    }

    for (auto &iter : arr) {
        sort(iter.second.begin(), iter.second.end(), compare);
    }
    arr3.assign(arr2.begin(), arr2.end());
    sort(arr3.begin(), arr3.end(), compare_map_value);

    for (auto i : arr3) {
        for (int j = 0; j < 2; j++) {
            if (j == 1 && arr[i.first].size() < 2) {
                continue;
            }
            answer.push_back(arr[i.first][j].second);
        }
    }

    return answer;
}