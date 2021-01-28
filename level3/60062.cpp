#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int size = weak.size();

    sort(dist.begin(), dist.end());

    for (int i = 0; i < size; i++) {
        weak.push_back(n + weak[i]);
    }

    for (int i = 1; i <= dist.size(); i++) {
        for (int j = 0; j < size; j++) {
            vector<int> temp = dist;
            do {
                int idx = 0;
                for (int k = 0; k < i; k++) {
                    int maximum = weak[j + idx] + temp[k];
                    idx++;
                    while (weak[j + idx] <= maximum) {
                        idx++;
                    }
                }
                if (idx >= size) {
                    return i;
                }
            } while (next_permutation(temp.begin(), temp.end()));
        }
    }

    return -1;
}