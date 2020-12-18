#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    for (int i = 0; i < A.size(); i++) {
        answer = answer + (A[i] * B[A.size() - i - 1]);
    }
    return answer;
}