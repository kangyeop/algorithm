#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    if (!isdigit(s[0])) {
        bool isMinus = false;
        if (s[0] == '-') {
            isMinus = true;
        }
        s.erase(0, 1);
        answer = stoi(s);
        if (isMinus) {
            answer *= -1;
        }
        return answer;
    }

    answer = stoi(s);

    return answer;
}