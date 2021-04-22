#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;

    vector<string> dp(101, "0");

    dp[2] = "1";
    dp[3] = "7";
    dp[4] = "4";
    dp[5] = "2";
    dp[6] = "6";
    dp[7] = "8";
    dp[8] = "10";
    dp[9] = "18";

    vector<string> numbers = { "1", "7", "4", "2", "0", "8" };

    for (int i = 10; i <= 100; i++) {
        for (int j = 2; j <= 7; j++) {
            if (j == 2) {
                dp[i] = dp[i - j] + numbers[j - 2];
                continue;
            }
            dp[i] = to_string(min(stoll(dp[i - j] + numbers[j - 2]), stoll(dp[i])));
        }
    }

    while (T--) {
        int n;
        cin >> n;

        string max = "";

        int temp = n;

        if (temp % 2) {
            max += "7";
            temp -= 3;
        }

        while (temp != 0) {
            max += "1";
            temp -= 2;
        }

        cout << dp[n] << " " << max << "\n";
    }
    return 0;
}