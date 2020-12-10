#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int         answer = 0;
    vector<int> arr;
    for (int i : moves) {
        for (int j = 0; j < board.size(); j++) {
            if (board[j][i - 1]) {
                arr.push_back(board[j][i - 1]);
                board[j][i - 1] = 0;
                break;
            }
        }
        int size = arr.size() - 1;
        if (size >= 1 && arr[size] == arr[size - 1]) {
            arr.pop_back();
            arr.pop_back();
            answer += 2;
        }
    }
    return answer;
}