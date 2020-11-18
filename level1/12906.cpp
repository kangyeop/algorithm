#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    int         post = -1;
    vector<int> answer;
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == post) {
            continue;
        }
        answer.push_back(arr[i]);
        post = arr[i];
    }

    return answer;
}