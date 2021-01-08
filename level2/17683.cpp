#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

string removeShop(string str) {
    vector<string> arr = { "A#", "C#", "D#", "F#", "G#" };
    vector<string> target = { "H", "I", "J", "K", "L" };

    for (int i = 0; i < 5; i++) {
        size_t previous = 0;
        size_t current;
        current = str.find(arr[i]);
        string newStr;
        while (current != string::npos) {
            string substring = str.substr(previous, current - previous);
            newStr += substring;
            newStr += target[i];

            previous = current + 2;
            current = str.find(arr[i], previous);
        }
        string substring = str.substr(previous, str.size() - previous);
        newStr += substring;

        str = newStr;
    }

    return str;
}

string makeFull(int time, string s) {
    string str = removeShop(s);
    string newStr = "";
    for (int i = 0; i < time; i++) {
        newStr += str[i % str.size()];
    }
    return newStr;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    int maxTime = 0;
    int firstStartHH = 0;
    int firstStartMM = 0;
    string targetStr = removeShop(m);
    for (int i = 0; i < musicinfos.size(); i++) {
        string s = musicinfos[i];
        vector<string> temp;

        size_t previous = 0;
        size_t current;

        current = s.find(',');

        while (current != string::npos) {
            string substring = s.substr(previous, current - previous);
            temp.push_back(substring);
            previous = current + 1;
            current = s.find(',', previous);
        }
        string substring = s.substr(previous, s.size() - previous);
        temp.push_back(substring);

        string startHH = temp[0].substr(0, 2);
        string startMM = temp[0].substr(3, 2);
        string endHH = temp[1].substr(0, 2);
        string endMM = temp[1].substr(3, 2);

        int time = (stoi(endHH) - stoi(startHH)) * 60 + (stoi(endMM) - stoi(startMM));
        string res = makeFull(time, temp[3]);
        if (res.find(targetStr) != string::npos) {
            if (maxTime < time) {
                maxTime = time;
                answer = temp[2];
                firstStartHH = stoi(startHH);
                firstStartMM = stoi(startMM);
            } else if (maxTime == time) {
                if (stoi(startHH) < firstStartHH) {
                    maxTime = time;
                    answer = temp[2];
                    firstStartHH = stoi(startHH);
                    firstStartMM = stoi(startMM);
                } else if (stoi(startHH) == firstStartHH) {
                    if (stoi(startMM) < firstStartMM) {
                        maxTime = time;
                        answer = temp[2];
                        firstStartHH = stoi(startHH);
                        firstStartMM = stoi(startMM);
                    }
                }
            }
        }
    }
    return answer;
}