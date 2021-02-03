#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> solution(vector<string> gems) {
    unordered_map<string, int> mp;
    set<string> st(gems.begin(), gems.end());

    int start = 0;
    int end = 0;

    for (auto i : gems) {
        mp[i]++;
        if (mp.size() == st.size())
            break;
        end++;
    }

    vector<int> answer({ 0, 0 });

    int Min = end - start;
    answer[0] = start + 1;
    answer[1] = end + 1;

    while (end < gems.size()) {
        string key = gems[start];
        mp[key]--;
        start++;

        if (mp[key] == 0) {
            end++;
            for (; end < gems.size(); end++) {
                mp[gems[end]]++;
                if (key == gems[end])
                    break;
            }
            if (end == gems.size())
                break;
        }
        if (Min > end - start) {
            answer[0] = start + 1;
            answer[1] = end + 1;
            Min = end - start;
        }
    }

    return answer;
}