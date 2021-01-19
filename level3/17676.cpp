#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<string> lines) {
    int answer = 0;
    if (lines.size() == 1) {
        return 1;
    }

    vector<int> startTimeSet;
    vector<int> endTimeSet;

    for (auto str : lines) {
        string h = str.substr(11, 2);
        string m = str.substr(14, 2);
        string s = str.substr(17, 2);
        string ms = str.substr(20, 3);
        float process = stof(str.substr(24, 5)) * 1000;

        int ih = stoi(h) * 3600 * 1000;
        int im = stoi(m) * 60 * 1000;
        int is = stoi(s) * 1000 + stoi(ms);

        int startTime = ih + im + is - process + 1;
        int endTime = ih + im + is;
        startTimeSet.push_back(startTime);
        endTimeSet.push_back(endTime);
    }

    for (int i = 0; i < endTimeSet.size(); i++) {
        int jobCount = 0;
        int endTime = endTimeSet[i] + 1000;
        for (int j = i; j < startTimeSet.size(); j++) {
            if (startTimeSet[j] < endTime) {
                jobCount++;
            }
        }
        answer = max(answer, jobCount);
    }

    return answer;
}