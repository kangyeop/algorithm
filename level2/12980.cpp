#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int makeBin(int a) {
    int index = 0;
    while (a) {
        if (a % 2) {
            index++;
        }
        a /= 2;
    }
    return index;
}

int solution(int n) {
    int ans = makeBin(n);
    return ans;
}