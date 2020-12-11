#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    int    num    = n;
    while (num) {
        int  res         = num % 3;
        bool isMultiples = false;
        if (!res) {
            res         = 4;
            isMultiples = true;
        }
        answer += to_string(res);
        num /= 3;
        if (isMultiples) {
            num -= 1;
        }
    }
    reverse(answer.begin(), answer.end());
    return answer;
}