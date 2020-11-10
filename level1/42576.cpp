#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    for (int i = 0; i < completion.size(); i++) {
        if (participant[i] == completion[i])
            continue;
        answer = participant[i];
        break;
    }
    if (answer == "") {
        answer = participant.back();
    }

    return answer;
}