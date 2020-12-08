#include <algorithm>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> d, int budget) {
    int         answer = 0;
    vector<int> arr;
    int         size = d.size();
    arr.assign(size + 1, 0);
    typedef vector<int>::iterator it;

    for (int i = 0; i < size; i++) {
        if (!d.size()) {
            break;
        }
        it min = min_element(d.begin(), d.end());
        if (budget >= *min) {
            budget -= *min;
            d.erase(min);
            answer++;
        } else {
            break;
        }
    }

    return answer;
}