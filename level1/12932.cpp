#include <string>
#include <vector>

using namespace std;

vector<int> solution(long long n) {
    string      s = to_string(n);
    vector<int> answer;
    for (int i = s.size() - 1; i >= 0; i--) {
        answer.push_back(s[i] - '0');
    }
    return answer;
}