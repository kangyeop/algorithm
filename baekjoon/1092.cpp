#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool compare(int a, int b) { return a > b; }

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> ship;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        ship.push_back(temp);
    }

    int m;
    cin >> m;

    vector<int> stuff;

    for (int i = 0; i < m; i++) {
        int temp;
        cin >> temp;
        stuff.push_back(temp);
    }

    sort(ship.begin(), ship.end(), compare);
    sort(stuff.begin(), stuff.end(), compare);

    vector<int> visit(m, 0);

    if (ship[0] < stuff[0]) {
        cout << -1 << endl;
        return 0;
    }

    int cnt = 0;

    while (!stuff.empty()) {
        cnt++;
        for (int i = 0; i < ship.size(); i++) {
            for (int j = 0; j < stuff.size(); j++) {
                if (ship[i] >= stuff[j]) {
                    stuff.erase(stuff.begin() + j);
                    break;
                }
            }
        }
    }

    cout << cnt << endl;
    return 0;
}
