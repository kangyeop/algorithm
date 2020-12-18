#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool comp(int a, int b) {
    string A = to_string(a);
    string B = to_string(b);
    return stoi(A + B) > stoi(B + A);
}

string solution(vector<int> numbers) {
    sort(numbers.begin(), numbers.end(), comp);
    string answer = "";
    int zeroCount = 0;
    for (auto i : numbers) {
        answer += to_string(i);
        if (!i) {
            zeroCount++;
        }
    }
    if (zeroCount == answer.size()) {
        answer = "0";
    }

    return answer;
}
