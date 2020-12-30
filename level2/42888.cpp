#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> arr;
    queue<pair<string, string>> que;
    for (auto s : record) {
        size_t previous = 0, current;
        vector<string> temp;
        current = s.find(' ');

        while (current != string::npos) {
            string substring = s.substr(previous, current - previous);
            previous = current + 1;

            temp.push_back(substring);
            current = s.find(' ', previous);
        }

        string substring = s.substr(previous, current - previous);
        temp.push_back(substring);

        if (temp[0] == "Enter") {
            auto iter = arr.find(temp[1]);
            if (iter == arr.end()) {
                arr.insert(pair<string, string>(temp[1], temp[2]));
            } else {
                iter->second = temp[2];
            }
            que.push(pair<string, string>(temp[1], "님이 들어왔습니다."));
            continue;
        }

        if (temp[0] == "Change") {
            auto iter = arr.find(temp[1]);
            iter->second = temp[2];
            continue;
        }
        que.push(pair<string, string>(temp[1], "님이 나갔습니다."));
    }

    while (!que.empty()) {
        auto front = que.front();
        auto iter = arr.find(front.first);
        answer.push_back(iter->second + front.second);
        que.pop();
    }
    return answer;
}