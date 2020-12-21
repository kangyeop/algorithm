#include <iostream>
#include <string>
#include <vector>

using namespace std;

string makeBin(int a) {
    string answer;
    while (a) {
        answer += to_string(a % 2);
        a /= 2;
    }
    return answer;
}

vector<int> solution(string s) {
    int count = 0;
    int zero = 0;
    string newString = "";
    vector<int> answer;
    while (true) {
        for (auto i : s) {
            if (i - '0') {
                newString += i;
            } else {
                zero++;
            }
        }
        count++;
        if (newString.size() == 1) {
            break;
        }
        s = makeBin(newString.size());
        newString = "";
    }
    answer.push_back(count);
    answer.push_back(zero);
    return answer;
}