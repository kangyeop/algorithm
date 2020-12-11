#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for (string i : skill_trees) {
        int  prevIndex = -1;
        bool isFine    = true;
        for (char j : i) {
            int index = (int)skill.find(j);
            if (index != -1) {
                if (prevIndex == (index - 1)) {
                    prevIndex = index;
                } else {
                    isFine = false;
                    break;
                }
            }
        }
        if (isFine) {
            answer++;
        }
    }
    return answer;
}