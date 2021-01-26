#include <algorithm>
#include <string>
#include <vector>

using namespace std;

bool check(vector<int> stones, int k, int mid) {
    int cnt = 0;
    for (int i = 0; i < stones.size(); i++) {
        if (stones[i] < mid) {
            cnt++;
            if (cnt >= k)
                return false;
        } else
            cnt = 0;
    }
    return true;
}

int solution(vector<int> stones, int k) {
    int answer = 0;

    int right = *max_element(stones.begin(), stones.end());
    int left = 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (check(stones, k, mid)) {
            left = mid + 1;
            if (answer < mid) {
                answer = mid;
            }
        } else {
            right = mid - 1;
        }
    }

    return answer;
}