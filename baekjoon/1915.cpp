#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<string> arr;

    arr.push_back("");

    for (int i = 0; i <= m; i++) {
        arr[0] += "0";
    }

    for (int i = 1; i <= n; i++) {
        string temp;
        cin >> temp;
        temp = "0" + temp;
        arr.push_back(temp);
    }

    vector<vector<int>> count(n + 1, vector<int>(m + 1, 0));

    int maxCount = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr[i][j] == '0') {
                continue;
            }
            count[i][j]
               = min(count[i - 1][j], min(count[i - 1][j - 1], count[i][j - 1])) + 1;
            if (count[i][j] > maxCount) {
                maxCount = count[i][j];
            }
        }
    }

    cout << maxCount * maxCount << endl;

    return 0;
}