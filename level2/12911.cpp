#include <string>
#include <vector>

using namespace std;

int makeBin(int a) {
    int count = 0;
    while (a) {
        if (a % 2) {
            count++;
        }
        a /= 2;
    }
    return count;
}

int solution(int n) {
    int answer = 0;
    int binCount = makeBin(n);
    int index = n + 1;
    while (true) {
        if (makeBin(index) == binCount) {
            break;
        }
        index++;
    }
    answer = index;
    return answer;
}