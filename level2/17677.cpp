#include <iostream>
#include <regex>
#include <string>
#include <vector>

using namespace std;

vector<string> makeSet(string str) {
    vector<string> arr;

    transform(str.begin(), str.end(), str.begin(), ::tolower);

    for (int i = 1; i < str.size(); i++) {
        if (isalpha(str[i]) && isalpha(str[i - 1])) {
            arr.push_back(str.substr(i - 1, 2));
        }
    }
    return arr;
}

int solution(string str1, string str2) {
    int answer = 0;
    vector<string> temp1 = makeSet(str1);
    vector<string> temp2 = makeSet(str2);
    if (!temp1.size() && !temp2.size()) {
        return 65536;
    }
    vector<bool> visit1;
    vector<bool> visit2;

    int sameCount = 0;

    visit1.assign(temp1.size(), false);
    visit2.assign(temp2.size(), false);
    for (int i = 0; i < temp1.size(); i++) {
        for (int j = 0; j < temp2.size(); j++) {
            if (temp1[i] == temp2[j]) {
                if (!visit2[j]) {
                    // cout << temp1[i] << " " << temp2[j] << endl;
                    visit2[j] = true;
                    visit1[i] = true;
                    sameCount++;
                    break;
                }
            }
        }
    }

    int sumCount = temp1.size() + temp2.size() - sameCount;
    double jnum = (double)((double)sameCount / (double)sumCount);
    answer = jnum * 65536;
    return answer;
}