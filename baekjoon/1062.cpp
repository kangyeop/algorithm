#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> alpha(26, 0);
vector<string> arr;
int n, k;
int answer = -1;

void checkAlpha(int nn, int cnt) {
    if (cnt == k) {
        int num = 0;
        for (int i = 0; i < n; i++) {
            string str = arr[i].substr(4, arr[i].size() - 8);
            bool flag = true;
            for (int j = 0; j < str.size(); j++) {
                if (alpha[str[j] - 'a'] == 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                num++;
            }
        }
        if (num > answer) {
            answer = num;
        }
    }
    for (int i = nn + 1; i < 26; i++) {
        if (alpha[i] == 0) {
            alpha[i]++;
            checkAlpha(i, cnt + 1);
            alpha[i] = 0;
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;

        arr.push_back(str);
    }

    if (k < 5) {
        cout << 0 << "\n";
        return 0;
    }

    k -= 5;
    alpha['a' - 'a']++;
    alpha['c' - 'a']++;
    alpha['t' - 'a']++;
    alpha['n' - 'a']++;
    alpha['i' - 'a']++;

    checkAlpha(0, 0);

    cout << answer << endl;

    return 0;
}