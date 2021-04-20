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

    vector<int> arr;
    vector<int> dist;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n - 1; i++) {
        int temp = arr[i + 1] - arr[i];
        dist.push_back(temp);
    }

    sort(dist.begin(), dist.end());

    int sum = 0;

    for (int i = 0; i < n - k; i++) {
        sum += dist[i];
    }
    cout << sum << "\n";
    return 0;
}