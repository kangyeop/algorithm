#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;

    answer.assign(arr1.size(), vector<int>(arr2.size(), 0));
    for (int i = 0; i < arr1.size(); i++) {
        for (int j = 0; j < arr2.size(); j++) {
            int sum = 0;
            for (int k = 0; k < arr2.size(); k++) {
                sum = sum + (arr1[i][k] * arr2[k][j]);
            }
            answer[i][j] = sum;
        }
    }
    return answer;
}