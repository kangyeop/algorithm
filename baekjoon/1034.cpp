#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<string> arr;

    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;

        arr.push_back(temp);
    }

    int k;
    cin >> k;

    int answer = -1;

    for (int i = 0; i < n; i++) {
        int zeroCount = 0;
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == '0')
                zeroCount++;
        }
        int cntt = 0;
        if (zeroCount <= k && k % 2 == zeroCount % 2) {
            for (int j = 0; j < n; j++) {
                if (arr[j] == arr[i]) {
                    cntt++;
                }
            }
        }
        answer = max(answer, cntt);
    }

    cout << answer;
}