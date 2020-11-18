#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int  size  = s.size();
    bool isOdd = false;
    if (size % 2) {
        isOdd = true;
    }
    string answer = "";
    if (isOdd) {
        answer += s[size / 2];
    } else {
        answer += s[size / 2 - 1];
        answer += s[size / 2];
    }
    return answer;
}