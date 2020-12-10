#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string dartResult) {
    vector<int> num;
    int         current = -1;
    for (auto i : dartResult) {
        if (isdigit(i)) {
            if (current != -1) {
                current = 10;
                continue;
            }
            current = i - '0';
            continue;
        }
        switch (i) {
        case 'S': {
            num.push_back(pow(current, 1));
            current = -1;
            break;
        }
        case 'D': {
            num.push_back(pow(current, 2));
            current = -1;
            break;
        }
        case 'T': {
            num.push_back(pow(current, 3));
            current = -1;
            break;
        }
        case '*': {
            current  = -1;
            int size = num.size();
            for (int i = size - 2; i < size; i++) {
                num[i] = num[i] * 2;
            }
            break;
        }
        case '#': {
            current  = -1;
            int temp = num.back() * -1;
            num.pop_back();
            num.push_back(temp);
            break;
        }
        default:
            break;
        }
    }

    int sum = 0;

    for (int i : num) {
        sum += i;
    }

    return sum;
}