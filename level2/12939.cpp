#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";

    vector<int> arr;

    size_t previous = 0, current;
    current = s.find(' ');

    while (current != string::npos) {
        string substring = s.substr(previous, current - previous);
        arr.push_back(stoi(substring));
        previous = current + 1;

        current = s.find(' ', previous);
    }

    string substring = s.substr(previous, current - previous);
    arr.push_back(stoi(substring));

    answer += to_string(*min_element(arr.begin(), arr.end()));
    answer += " ";
    answer += to_string(*max_element(arr.begin(), arr.end()));

    return answer;
}