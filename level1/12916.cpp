#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

bool solution(string s) {
    bool answer = true;

    transform(s.begin(), s.end(), s.begin(), ::tolower);

    int pCount = 0;
    int yCount = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'p') {
            pCount++;
        }
        if (s[i] == 'y') {
            yCount++;
        }
    }
    if (yCount == pCount) {
        return true;
    } else {
        return false;
    }
}