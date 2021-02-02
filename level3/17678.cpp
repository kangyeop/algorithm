#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int makeInt(string str) {
    string hh = str.substr(0, 2);
    string mm = str.substr(3, 2);

    int h = stoi(hh) * 60;
    int m = stoi(mm);
    return h + m;
}

string makeTime(int num) {
    string hh = to_string(num / 60);
    if (hh.size() == 1) {
        hh = "0" + hh;
    }
    num = num % 60;
    string mm = to_string(num);
    if (mm.size() == 1) {
        mm = "0" + mm;
    }

    string time = hh;
    time += ":";
    time += mm;

    return time;
}

bool compare(int a, int b) { return a < b; }

string solution(int n, int t, int m, vector<string> timetable) {
    vector<int> arriveTime;

    sort(timetable.begin(), timetable.end());

    for (auto i : timetable) {
        arriveTime.push_back(makeInt(i));
    }

    int currentTime = makeInt("09:00");

    int res = 0;
    int idx = 0;

    for (int i = 0; i < n; i++) {
        int timeCount = 0;
        for (int j = idx; j < arriveTime.size(); j++) {
            if (arriveTime[j] <= currentTime) {
                idx++;
                timeCount++;
            } else {
                break;
            }
            if (timeCount >= m) {
                break;
            }
        }
        if (i == n - 1) {
            if (timeCount >= m) {
                res = arriveTime[idx - 1] - 1;
            } else {
                res = currentTime;
            }
        }
        currentTime = currentTime + t;
        if (currentTime >= 1440) {
            break;
        }
    }

    return makeTime(res);
}