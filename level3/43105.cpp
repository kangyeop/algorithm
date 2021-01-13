#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<vector<int>> arr(triangle.size(), vector<int>(triangle.size(), -1));

    arr[0][0] = triangle[0][0];

    for (int i = 1; i < triangle.size(); i++) {
        arr[i][0] = triangle[i][0] + arr[i - 1][0];
        arr[i][i] = triangle[i][i] + arr[i - 1][i - 1];
    }

    for (int i = 1; i < triangle.size(); i++) {
        for (int j = 1; j < triangle[i].size() - 1; j++) {
            arr[i][j] = triangle[i][j] + max(arr[i - 1][j], arr[i - 1][j - 1]);
        }
    }

    answer = *max_element(arr[triangle.size() - 1].begin(),
                          arr[triangle.size() - 1].end());

    return answer;
}