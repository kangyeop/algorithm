#include <iostream>
#include <string>
#include <vector>

using namespace std;

int num;
int answer = 0;

void dfs(int a, int index) {
    if (a + index == num) {
        answer++;
        return;
    }
    if (a + index < num) {
        dfs(a + index, index + 1);
    }
}

int solution(int n) {
    num = n;
    for (int i = 1; i <= n; i++) {
        dfs(0, i);
    }
    return answer;
}