#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;
int add;

bool compare(int x, int y) { return x < y; }

bool start(int dist) {
    int cnt = 0;
    for (int i = 0; i < arr.size() - 1; i++) {
        int d = arr[i + 1] - arr[i];
        int val;
        if (d / dist > 0) {
            if (d % dist == 0)
                val = (d / dist) - 1;
            else
                val = (d / dist);
            cnt += val;
        }
    }
    if (cnt <= add)
        return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, l;
    cin >> n >> m >> l;

    add = m;

    arr.push_back(0);
    arr.push_back(l);

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    sort(arr.begin(), arr.end());

    int low = 0, high = l, mid, result;

    while (low <= high) {
        mid = low + (high - low) / 2;
        if (start(mid)) {
            high = mid - 1;
            result = mid;
        } else
            low = mid + 1;
    }

    cout << result << endl;

    return 0;
}
