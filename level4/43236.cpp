#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    int left = 0;
    int right = distance;

    sort(rocks.begin(), rocks.end());

    while (left <= right) {
        int mid = (left + right) / 2;
        int count = 0;
        int removeIdx = -1;
        for (int i = 0; i <= rocks.size(); i++) {
            int d;
            if (removeIdx == -1) {
                d = rocks[i];
            } else if (i == rocks.size()) {
                d = distance - rocks[i - 1];
            } else {
                d = rocks[i] - rocks[removeIdx];
            }

            if (d < mid) {
                count++;
            } else
                removeIdx = i;
        }
        if (count > n) {
            right = mid - 1;
        } else {
            left = mid + 1;
            if (answer < mid) {
                answer = mid;
            }
        }
    }
    return answer;
}