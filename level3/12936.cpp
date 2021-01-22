#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

long long getFactorial(int n) {
    long long res = 1;
    for (long long i = 1; i <= n; i++) {
        res *= i;
    }
    return res;
}

vector<int> solution(int n, long long k) {
    vector<int> answer;
    set<int> st;
    for (int i = 1; i <= n; i++) {
        st.insert(i);
    }
    k = k - 1;
    for (int i = n - 1; i >= 0; i--) {
        long long fac = getFactorial(i);
        answer.push_back(*next(st.begin(), k / fac));
        st.erase(next(st.begin(), k / fac));
        k = k % fac;
    }
    return answer;
}