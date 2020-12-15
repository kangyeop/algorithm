#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    string prev = "";
    vector<int> arr;

    for (int j = 1; j <= s.size(); j++) {
        int count = 0;
        string answer = "";
        for (int i = 0; i < s.size(); i += j) {
            string current = s.substr(i, j);

            if (!i) {
                count++;
                prev = current;
                continue;
            }

            if (current == prev) {
                count++;
                continue;
            }

            if (count != 1) {
                answer += to_string(count);
            }

            answer += prev;
            prev = current;
            count = 1;
        }

        if (count != 1) {
            answer += to_string(count);
        }
        answer += prev;
        arr.push_back(answer.size());
    }

    return *min_element(arr.begin(), arr.end());
}