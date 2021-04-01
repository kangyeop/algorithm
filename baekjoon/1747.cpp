#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<bool> isPrime;
int N;

void erathos() {
    isPrime.assign(1004000, true);
    isPrime[1] = false;

    for (int i = 2; i * i < 1004000; i++) {
        if (isPrime[i] == false)
            continue;
        for (int j = i + i; j < 1004000; j += i) {
            isPrime[j] = false;
        }
    }
}

bool isSp(int n) {
    string new_num = to_string(n);
    string num = to_string(n);

    reverse(new_num.begin(), new_num.end());

    if (num != new_num) {
        return false;
    }

    return true;
}

int main() {
    int n;
    cin >> n;

    erathos();
    int i = n;

    while (1) {
        if (isPrime[i] && isSp(i)) {
            cout << i << endl;
            break;
        }
        i++;
    }

    return 0;
}