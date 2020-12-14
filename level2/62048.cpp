#include <algorithm>
#include <iostream>

using namespace std;

int GCD(int a, int b) {
    if (a % b) {
        return GCD(b, a % b);
    }
    return b;
}

long long solution(int w, int h) {
    long long answer = 1;
    int       gcd    = GCD(max(w, h), min(w, h));

    long long x = w;
    long long y = h;

    long long total = x * y;

    answer = total - (w + h - gcd);
    return answer;
}
