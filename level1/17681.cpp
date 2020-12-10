#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> makeBin(int a, int n) {
    vector<int> bin;
    bin.assign(n, 0);
    int index = 0;
    while (a) {
        bin[n - index - 1] = a % 2;
        a /= 2;
        index++;
    }
    return bin;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for (int i = 0; i < n; i++) {
        vector<int> temp  = makeBin(arr1[i], n);
        vector<int> temp1 = makeBin(arr2[i], n);
        string      line  = "";
        for (int j = 0; j < n; j++) {
            if (temp[j] == 1 || temp1[j] == 1) {
                line += '#';
            } else {
                line += ' ';
            }
        }
        answer.push_back(line);
    }
    return answer;
}