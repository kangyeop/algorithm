#include <algorithm>
#include <cmath>
#include <iostream>
#include <queue>

using namespace std;

int n;
priority_queue<long long, vector<long long>, greater<long long>> arr;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            long long temp;
            cin >> temp;

            if (arr.size() < n) {
                arr.push(temp);
            } else {
                if (arr.top() < temp) {
                    arr.pop();
                    arr.push(temp);
                }
            }
        }
    }

    cout << arr.top() << "\n";

    return 0;
}