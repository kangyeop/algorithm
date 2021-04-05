#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<string> answer;

bool isPrime(int num) {
    if (num == 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (!(num % i)) {
            return false;
        }
    }
    return true;
}

void dfs(string num, int depth) {
    if (depth == n) {
        answer.push_back(num);
        return;
    }
    for (int i = 1; i < 10; i++) {
        string str = num + to_string(i);
        if (isPrime(stoi(str))) {
            dfs(str, depth + 1);
        }
    }
}

int main() {
    cin >> n;

    dfs("", 0);

    sort(answer.begin(), answer.end());

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << endl;
    }

    return 0;
}