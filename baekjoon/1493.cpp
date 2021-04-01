#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<int, int, greater<int>> mp;
int result = 0;
bool jud = true;

void solved(int l, int w, int h) {
    if (!jud) {
        return;
    }
    if (l == 0 || w == 0 || h == 0)
        return;

    for (auto iter = mp.begin(); iter != mp.end(); iter++) {
        int size = iter->first;
        int count = iter->second;
        if (size <= l && size <= w && size <= h && count > 0) {
            iter->second--;
            result++;
            solved(l, w, h - size);
            solved(size, w - size, size);
            solved(l - size, w, size);
            return;
        }
    }

    jud = false;
}

int main() {
    int l, w, h;
    cin >> l >> w >> h;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        int key = pow(2, temp1);
        mp[key] = temp2;
    }

    solved(l, w, h);

    if (!jud) {
        cout << -1 << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}
