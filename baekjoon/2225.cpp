#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector<vector<int>> arr(201, vector<int>(201, 0));

    for (int i = 0; i <= n; i++) {
        arr[0][i] = 0;
        arr[1][i] = 1;
    }

    for (int i = 1; i <= k; i++) {
        for (int j = 0; j <= n; j++) {
            for (int x = 0; x <= j; x++) {
                arr[i][j] = (arr[i][j] + arr[i - 1][j - x]) % 1000000000;
            }
        }
    }

    cout << arr[k][n] << endl;

    return 0;
}