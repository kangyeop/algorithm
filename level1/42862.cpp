#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int                           cnt = 0;
    typedef vector<int>::iterator it;
    vector<int>                   arr;
    for (it i = lost.begin(); i != lost.end(); i++) {
        it iter = find(reserve.begin(), reserve.end(), *i);
        if (iter != reserve.end()) {
            reserve.erase(iter);
            arr.push_back(*i);
            continue;
        }
    }

    for (it i = lost.begin(); i != lost.end(); i++) {
        int a = *i - 1;
        int b = *i + 1;
        if (find(arr.begin(), arr.end(), *i) != arr.end()) {
            continue;
        }
        it iter = find(reserve.begin(), reserve.end(), a);
        if (iter != reserve.end()) {
            reserve.erase(iter);
            continue;
        }
        iter = find(reserve.begin(), reserve.end(), b);
        if (iter != reserve.end()) {
            reserve.erase(iter);
            continue;
        }

        cnt++;
    }

    return n - cnt;
}