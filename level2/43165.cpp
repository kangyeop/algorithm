#include <string>
#include <vector>

using namespace std;

int answer = 0;
int tar = 0;
vector<int> arr;

void checkIsTarget(int number, int depth) {
    if (depth == arr.size()) {
        if (number == tar) {
            answer++;
        }
        return;
    }
    checkIsTarget(number + arr[depth], depth + 1);
    checkIsTarget(number - arr[depth], depth + 1);
}

int solution(vector<int> numbers, int target) {
    tar = target;
    arr = numbers;
    checkIsTarget(0, 0);
    return answer;
}