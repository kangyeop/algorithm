#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    long long maxNum = -1;

    vector<long long> arr;
    for (int i = 0; i < n; i++) {
        long long temp;
        cin >> temp;
        if (temp > maxNum) {
            maxNum = temp;
        }
        arr.push_back(temp);
    }

    long long left = 0;
    long long right = maxNum;
    long long result = 0;
    while (left <= right) {
        long long mid = (left + right) / 2;
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] > mid) {
                sum += arr[i] - mid;
            }
        }
        if (sum >= m) {
            left = mid + 1;
            if (result < mid)
                result = mid;
        } else {
            right = mid - 1;
        }
    }

    cout << result << "\n";

    return 0;
}