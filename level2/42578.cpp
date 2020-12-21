#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    vector<string> arr;
    vector<int> size;
    for (int i = 0; i < clothes.size(); i++) {
        auto iter = find(arr.begin(), arr.end(), clothes[i][1]);
        if (iter == arr.end()) {
            arr.push_back(clothes[i][1]);
            size.push_back(1);
            continue;
        }
        int index = iter - arr.begin();
        size[index]++;
    }

    for (auto i : size) {
        answer *= i + 1;
    }

    return answer - 1;
}