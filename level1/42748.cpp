#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for (int i = 0; i < commands.size(); i++) {
        int x = commands[i][0] - 1;
        int y = commands[i][1] - 1;
        int k = commands[i][2] - 1;

        vector<int> copyArr;
        for (int i = x; i <= y; i++) {
            copyArr.push_back(array[i]);
        }
        sort(copyArr.begin(), copyArr.end());
        answer.push_back(copyArr[k]);
    }

    return answer;
}