#include <algorithm>
#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    regex reg("(100+1+|01)+");

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;

        cout << (regex_match(temp, reg) ? "YES" : "NO");
        cout << endl;
    }

    return 0;
}
