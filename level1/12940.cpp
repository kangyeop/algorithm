#include <iostream>
#include <string>
#include <vector>

using namespace std;

int GCD(int a, int b) {
    if (a % b) {
        return GCD(b, a % b);
    }
    return b;
}

vector<int> solution(int n, int m) {
    vector<int> answer;
    int         gcd;
    if (n > m) {
        gcd = GCD(n, m);
    } else {
        gcd = GCD(m, n);
    }
    long lcm = n * m / gcd;
    answer.push_back(gcd);
    answer.push_back(lcm);

    return answer;
}