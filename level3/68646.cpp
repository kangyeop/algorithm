#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    vector<int> dp1(a.size(), 0);
    dp1[0] = a[0];
    vector<int> dp2(a.size(), 0);
    dp2[a.size() - 1] = a[a.size() - 1];

    for (int i = 1; i < a.size(); i++) {
        dp1[i] = min(dp1[i - 1], a[i]);
    }
    for (int i = a.size() - 2; i >= 0; i--) {
        dp2[i] = min(dp2[i + 1], a[i]);
    }

    for (int i = 0; i < a.size(); i++) {
        if (a[i] <= dp1[i] || a[i] <= dp2[i]) {
            answer++;
        }
    }

    return answer;
}