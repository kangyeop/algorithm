#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int answer = 0;
vector<int> numbers;
vector<bool> visit;

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

void makeSum(int depth, int n, int index) {
    if (depth == 3) {
        if (isPrime(n)) {
            answer++;
        }
        return;
    }
    for (int i = index; i < numbers.size(); i++) {
        if (!visit[i]) {
            visit[i] = true;
            makeSum(depth + 1, n + numbers[i], i);
            visit[i] = false;
        }
    }
}

int solution(vector<int> nums) {
    numbers = nums;
    visit.assign(nums.size(), false);
    makeSum(0, 0, 0);
    return answer;
}