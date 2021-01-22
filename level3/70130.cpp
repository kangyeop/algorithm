#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    map<int, int> mp;
    for (int i = 0; i < a.size(); i++) {
        int tar = a[i];
        auto iter = mp.find(tar);
        if (iter == mp.end()) {
            mp.insert({ tar, 1 });
            continue;
        }
        iter->second++;
    }

    for (auto iter = mp.begin(); iter != mp.end(); iter++) {
        if (iter->second < 2 || iter->second < answer) {
            continue;
        }

        int tar = iter->first;
        int result = 0;
        for (int i = 0; i < a.size() - 1; i++) {
            if (a[i] != tar && a[i + 1] != tar)
                continue;
            if (a[i] == a[i + 1])
                continue;
            result++;
            i++;
        }
        answer = max(answer, result);
    }
    return answer * 2;
}