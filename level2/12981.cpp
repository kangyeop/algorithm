#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    vector<int> arr;
    vector<string> save;
    arr.assign(n, 0);
    char prev = ' ';
    for (int i = 0; i < words.size(); i++) {
        if (prev == ' ') {
            prev = words[i][words[i].size() - 1];
            arr[0]++;

            save.push_back(words[i]);
            continue;
        }
        string temp = words[i];
        int tempSize = temp.size();
        if (find(save.begin(), save.end(), temp) != save.end()) {
            answer.push_back(i % n + 1);
            answer.push_back(arr[i % n] + 1);
            break;
        }
        save.push_back(temp);
        if (prev != temp[0]) {
            answer.push_back(i % n + 1);
            answer.push_back(arr[i % n] + 1);
            break;
        }
        prev = temp[temp.size() - 1];
        arr[i % n]++;
    }

    if (!answer.size()) {
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}