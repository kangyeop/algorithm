#include <cmath>
#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    vector<int> num;

    int n     = x;
    int index = 5;

    while (n) {
        num.push_back(n / (int)pow(10, index));
        n = n % (int)pow(10, index);
        index--;
    }

    int sum = 0;
    for (auto i : num) {
        sum += i;
    }
    if (x % sum) {
        return false;
    }

    return true;
}