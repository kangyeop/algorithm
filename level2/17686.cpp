#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct compare {
    bool operator()(vector<string> a, vector<string> b) {
        string x = a[0];
        string y = b[0];

        transform(x.begin(), x.end(), x.begin(), ::tolower);
        transform(y.begin(), y.end(), y.begin(), ::tolower);

        if (x != y) {
            return x > y;
        }
        if (stoi(a[1]) != stoi(b[1])) {
            return stoi(a[1]) > stoi(b[1]);
        }
        return stoi(a[2]) > stoi(b[2]);
    }
};

vector<string> solution(vector<string> files) {
    priority_queue<vector<string>, vector<vector<string>>, compare> arr;
    int index = 0;
    for (auto i : files) {
        bool startDigist = false;
        int startIndex = -1;

        vector<string> temp;
        for (int j = 0; j < i.size(); j++) {
            if (isdigit(i[j])) {
                if (!startDigist) {
                    temp.push_back(i.substr(0, j));
                    startIndex = j;
                }
                startDigist = true;
                continue;
            }
            if (startDigist) {
                temp.push_back(i.substr(startIndex, j - startIndex));
                startDigist = false;
                break;
            }
        }
        if (startDigist) {
            temp.push_back(i.substr(startIndex, i.size() - startIndex));
            startDigist = false;
        }
        temp.push_back(to_string(index));
        temp.push_back(i);
        arr.push(temp);
        index++;
    }

    vector<string> answer;

    while (!arr.empty()) {
        auto temp = arr.top();
        answer.push_back(temp[3]);
        arr.pop();
    }

    return answer;
}