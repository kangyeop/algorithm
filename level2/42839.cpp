#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<bool> visit;
vector<int> arr;
int answer = 0;
string number;
int sSize;

bool isPrime(int a) {
    int n = sqrt(a);
    if (a < 2) {
        return false;
    }
    for (int i = 2; i <= n; i++) {
        if (!(a % i)) {
            return false;
        }
    }
    return true;
}

void permutation(string a) {
    if (a != "" && isPrime(stoi(a))) {
        auto iter = find(arr.begin(), arr.end(), stoi(a));
        if (iter == arr.end()) {
            arr.push_back(stoi(a));
            answer++;
        }
    }
    for (int i = 0; i < sSize; i++) {
        if (!visit[i]) {
            visit[i] = true;
            permutation(a + number[i]);
            visit[i] = false;
        }
    }
}

int solution(string numbers) {
    number = numbers;
    sSize = numbers.size();
    visit.assign(sSize, false);
    permutation("");
    return answer;
}