#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool comp(vector<int> a, vector<int> b) { return a[0] < b[0]; }

int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(), routes.end(), comp);
    int temp = routes[0][1];
    for (int i = 0; i < routes.size() - 1; i++) {
        if (temp < routes[i][0]) {
            answer++;
            temp = routes[i][1];
        }
        if (temp > routes[i][1])
            temp = routes[i][1];
    }
    return answer;
}