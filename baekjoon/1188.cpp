#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int GCD(int a, int b) {
    if (a % b) {
        return GCD(b, a % b);
    }
    return b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int m;
    cin >> m;

    if (n > m && n % m == 0) {
        cout << 0 << endl;
        return 0;
    }

    else {
        int gc = GCD(n, m);
        cout << m - gc << endl;
    }

    return 0;
}
