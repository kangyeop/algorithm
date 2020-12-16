#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;

    sort(people.begin(), people.end());

    int i = 0;

    for (int j = people.size() - 1; j >= i; j--) {
        if (i == j) {
            answer++;
            continue;
        }
        if (people[j] + people[i] <= limit) {
            i++;
            answer++;
        } else {
            answer++;
        }
    }

    return answer;
}