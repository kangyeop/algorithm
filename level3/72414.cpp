#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long makeInt(string str) {
    string hh = str.substr(0, 2);
    string mm = str.substr(3, 2);
    string ss = str.substr(6, 2);

    long long h = stoi(hh) * 3600;
    long long m = stoi(mm) * 60;
    long long s = stoi(ss);
    return h + m + s;
}

string makeTime(long long num) {
    string hh = to_string(num / 3600);
    if (hh.size() == 1) {
        hh = "0" + hh;
    }
    num = num % 3600;
    string mm = to_string(num / 60);
    if (mm.size() == 1) {
        mm = "0" + mm;
    }
    num = num % 60;
    string ss = "";
    if (to_string(num).size() == 1) {
        ss += "0";
    }
    ss += to_string(num);
    string time = hh;
    time += ":";
    time += mm;
    time += ":";
    time += ss;
    return time;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "00:00:00";
    int playTime = makeInt(play_time);
    int advTime = makeInt(adv_time);

    vector<long long> totalTime;
    totalTime.assign(playTime + 1, 0);

    for (auto str : logs) {
        long long startTime = makeInt(str.substr(0, 8));
        long long endTime = makeInt(str.substr(9, 8));
        totalTime[startTime] = totalTime[startTime] + 1;
        totalTime[endTime] = totalTime[endTime] - 1;
    }

    for (int i = 1; i <= playTime; i++) {
        totalTime[i] = totalTime[i] + totalTime[i - 1];
    }

    for (int i = 1; i <= playTime; i++) {
        totalTime[i] = totalTime[i] + totalTime[i - 1];
    }

    long long maxTime = 0;

    for (int i = advTime - 1; i <= playTime; i++) {
        long long time;
        if (i >= advTime) {
            time = totalTime[i] - totalTime[i - advTime];
        } else {
            time = totalTime[i];
        }

        if (time > maxTime) {
            maxTime = time;
            answer = makeTime(i - advTime + 1);
        }
    }

    return answer;
}