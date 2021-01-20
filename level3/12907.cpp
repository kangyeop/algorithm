#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> money) {
    vector<int> dp1;
    vector<int> dp2;
    dp1.assign(n + 1, 0);
    dp2.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int price = money[0];
        if (!(i % price)) {
            dp1[i] = 1;
        }
    }
    for (int i = 1; i < money.size(); i++) {
        int price = money[i];
        for (int j = 1; j <= n; j++) {
            dp2[j] = dp1[j];
            if (j == price) {
                dp2[j]++;
            }
            if (j - price > 0) {
                dp2[j] += dp2[j - price];
            }
        }
        dp1 = dp2;
    }
    return dp2[n];
}