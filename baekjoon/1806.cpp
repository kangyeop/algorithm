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

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    int left, right;
    left = 0;
    right = 0;

    int sum = 0;
    int result = numeric_limits<int>::max();
    while (1) {
        if (sum >= k) {
            result = min(right - left, result);
            sum -= arr[left];
            left++;
        } else if (right == n) {
            break;
        } else {
            sum += arr[right];
            right++;
        }
    }

    if (result == numeric_limits<int>::max()) {
        cout << 0 << endl;
    } else
        cout << result << endl;
    return 0;
}