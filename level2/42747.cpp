#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int size = citations.size();
    sort(citations.begin(), citations.end());
    for (int i = 1; i <= size; i++) {
        int count = 0;
        for (int j = 0; j < size; j++) {
            if (citations[j] >= i) {
                break;
            }
            count++;
        }
        if (size - count >= i) {
            answer = i;
        }
    }
    return answer;
}
