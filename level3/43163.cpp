#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string wanted;

int dfs(vector<string> words, string str, int num) {
    if (str == wanted) {
        return num;
    }
    int size = wanted.size();
    int minNum = numeric_limits<int>::max();
    for (int j = 0; j < words.size(); j++) {
        int sameAlpha = 0;
        for (int i = 0; i < size; i++) {
            if (words[j][i] == str[i]) {
                sameAlpha++;
            }
        }
        if (sameAlpha + 1 == size) {
            vector<string> temp;
            temp.insert(temp.end(), words.begin(), words.begin() + j);
            temp.insert(temp.end(), words.begin() + j + 1, words.end());
            minNum = min(minNum, dfs(temp, words[j], num + 1));
        }
    }
    return minNum;
}

int solution(string begin, string target, vector<string> words) {
    wanted = target;
    int answer = 0;
    auto iter = find(words.begin(), words.end(), target);
    if (iter == words.end()) {
        return 0;
    }

    answer = dfs(words, begin, 0);
    return answer;
}