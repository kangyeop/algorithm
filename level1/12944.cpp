#include <iostream>
#include <vector>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    for (auto i : arr) {
        answer += i;
    }
    answer /= arr.size();
    return answer;
}