#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<vector<long long>> arr(n, vector<long long>(4, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> arr[i][j];
        }
    }

    vector<long long> v;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            v.push_back(arr[i][2] + arr[j][3]);
        }
    }

    sort(v.begin(), v.end());

    long long result = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            long long sum = arr[i][0] + arr[j][1];
            auto low = lower_bound(v.begin(), v.end(), -sum) - v.begin();
            auto upp = upper_bound(v.begin(), v.end(), -sum) - v.begin();

            if (v[low] == -sum) {
                result += (upp - low);
            }
        }
    }

    cout << result << "\n";

    return 0;
}