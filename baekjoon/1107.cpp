#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> arr;
int n;

bool isFine(int k) {
    string target = to_string(k);
    for (int j = 0; j < n; j++) {
        if (target.find(arr[j] + '0') != string::npos) {
            return false;
        }
    }

    return true;
}

int main() {
    int INF = 1000007;

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    cin >> n;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    int start = 100;

    int tar = start;

    int minCount = INF;

    for (int i = 0; i < INF; i++) {
        if (isFine(i)) {
            int cNum = abs(i - t);
            cNum += to_string(i).size();
            minCount = min(cNum, minCount);
        }
    }

    int hundred = abs(t - 100);

    minCount = min(hundred, minCount);

    cout << minCount << endl;

    return 0;
}
