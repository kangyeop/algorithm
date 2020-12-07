#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int         aCount   = 0;
    int         bCount   = 0;
    int         cCount   = 0;
    int         arr1[5]  = { 1, 2, 3, 4, 5 };
    int         arr2[8]  = { 2, 1, 2, 3, 2, 4, 2, 5 };
    int         arr3[10] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };
    for (int i = 0; i < answers.size(); i++) {
        if (arr1[i % 5] == answers[i]) {
            aCount++;
        }
        if (arr2[i % 8] == answers[i]) {
            bCount++;
        }
        if (arr3[i % 10] == answers[i]) {
            cCount++;
        }
    }
    int result = max(max(aCount, bCount), cCount);

    if (result == aCount) {
        answer.push_back(1);
    }
    if (result == bCount) {
        answer.push_back(2);
    }
    if (result == cCount) {
        answer.push_back(3);
    }

    return answer;
}