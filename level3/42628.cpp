#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool comp(int a, int b) { return a > b; }

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    vector<int> arr;
    for (auto i : operations) {
        char oper = i[0];
        switch (oper) {
        case 'I': {
            string str = i.substr(2, i.size() - 2);
            arr.push_back(stoi(str));
            break;
        }
        case 'D': {
            char str = i[2];
            if (str == '-') {
                if (arr.size())
                    arr.pop_back();
            } else {
                if (arr.size())
                    arr.erase(arr.begin());
            }
            break;
        }
        default:
            break;
        }
        sort(arr.begin(), arr.end(), comp);
    }

    if (!arr.size()) {
        answer.push_back(0);
        answer.push_back(0);
        return answer;
    }
    if (arr.size() == 1) {
        answer.push_back(arr[0]);
        answer.push_back(arr[0]);
        return answer;
    }
    answer.push_back(arr[0]);
    answer.push_back(arr[arr.size() - 1]);

    return answer;
}