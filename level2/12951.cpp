#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";

    bool isFirst = true;

    for (auto i : s) {
        if (i == ' ') {
            isFirst = true;
            answer += ' ';
            continue;
        }
        if (isFirst) {
            answer += toupper(i);
            isFirst = false;
        } else {
            answer += tolower(i);
        }
    }
    return answer;
}