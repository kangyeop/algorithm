#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(string msg) {
    vector<string> alph;

    vector<int> answer;

    for (char i = 'A'; i <= 'Z'; i++) {
        string str = "";
        str += i;
        alph.push_back(str);
    }

    for (int i = 0; i < msg.size(); i++) {
        bool isThere = true;
        string str = "";
        int index = 0;
        int target = -1;
        while (isThere) {
            str += msg[i + index];
            auto iter = find(alph.begin(), alph.end(), str);
            if (iter != alph.end()) {
                target = iter - alph.begin() + 1;
                index++;
                continue;
            }
            isThere = false;
        }
        i += index - 1;
        answer.push_back(target);
        alph.push_back(str);
    }

    return answer;
}