#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> arr;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    sort(arr.begin(), arr.end());

    int left = 0;
    int right = n - 1;

    int resA = arr[left];
    int resB = arr[right];

    int resLiquid = abs(arr[left] + arr[right]);

    while (left != right) {
        int sum = arr[left] + arr[right];

        if (abs(sum) < resLiquid) {
            resLiquid = abs(sum);
            resA = arr[left];
            resB = arr[right];
        }

        if (sum > 0) {
            right--;
        } else if (sum == 0) {
            break;
        } else {
            left++;
        }
    }

    cout << resA << " " << resB << endl;

    return 0;
}