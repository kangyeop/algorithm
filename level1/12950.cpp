#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    int                 n1 = arr1.size();
    int                 n2 = arr1[0].size();
    answer.assign(n1, vector<int>(n2, 0));
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            cout << arr1[i][j] << " " << arr2[i][j] << endl;
            answer[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
    return answer;
}