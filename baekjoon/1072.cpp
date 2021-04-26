#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    double X, Y;
    cin >> X >> Y;

    double Z = floor(100 * Y / X);
    if (Z >= (double)99) {
        cout << -1 << "\n";
        return 0;
    }

    int left = 1;
    int right = X + 1;
    int result;
    while (left <= right) {
        double mid = (left + right) / 2;
        double newP = floor((100 * (Y + mid)) / (X + mid));
        if (newP > Z) {
            right = mid - 1;
            result = mid;
        } else {
            left = mid + 1;
        }
    }

    cout << result << endl;

    return 0;
}