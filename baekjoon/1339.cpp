#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

bool compare(string a, string b) { return a.size() > b.size(); }

int main() {
    int n;
    cin >> n;

    vector<int> alpha(26, 0);

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < str.size(); j++) {
            alpha[str[j] - 'A'] += pow(10, (str.size() - j) - 1);
        }
    }

    int sum = 0;

    for (int i = 9; i >= 0; i--) {
        auto iter = max_element(alpha.begin(), alpha.end());
        sum += i * (*iter);
        alpha[iter - alpha.begin()] = 0;
    }

    cout << sum << endl;
    return 0;
}