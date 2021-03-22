#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;

    cin >> str;

    string s = str.substr(0, 1);
    for (int i = 1; i < str.size(); i++) {
        if (s[i - 1] < str[i]) {
            s = str[i] + s;
        } else {
            s = s + str[i];
        }
    }

    reverse(s.begin(), s.end());
    cout << s;

    return 0;
}