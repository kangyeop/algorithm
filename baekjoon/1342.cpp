#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int getFac(int a) {
    int cnt = 1;
    for (int i = 1; i <= a; i++) {
        cnt *= i;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    unordered_map<char, int> arr;

    string temp;
    cin >> temp;

    for (int i = 0; i < temp.size(); i++) {
        arr[temp[i]]++;
    }

    sort(temp.begin(), temp.end());

    int answer = 0;

    do {
        bool flag = true;
        for (int i = 0; i < temp.size() - 1; i++) {
            if (temp[i] == temp[i + 1]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            answer++;
        }
    } while (next_permutation(temp.begin(), temp.end()));

    cout << answer << endl;
}