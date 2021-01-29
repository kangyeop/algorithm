#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(B.begin(), B.end());
    sort(A.begin(), A.end());
    int bIndex = 0;
    for (int i = 0; i < A.size(); i++) {
        for (int j = bIndex; j < B.size(); j++) {
            if (A[i] < B[j]) {
                answer++;
                bIndex = j + 1;
                break;
            }
        }
    }
    return answer;
}