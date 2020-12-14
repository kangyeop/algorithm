#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    int currentWeight = 0;

    queue<int> trucks;
    for (auto i : truck_weights) {
        trucks.push(i);
    }
    queue<pair<int, int>> que;
    while (!trucks.empty()) {
        int            truckFront = trucks.front();
        pair<int, int> queFront   = que.front();

        answer++;

        if (answer - queFront.second >= bridge_length) {
            que.pop();
            currentWeight -= queFront.first;
        }

        if (currentWeight + truckFront > weight) {
            continue;
        }

        trucks.pop();
        que.push(pair<int, int>(truckFront, answer));
        currentWeight += truckFront;
    }

    while (!que.empty()) {
        answer++;
        pair<int, int> queFront = que.front();
        if (answer - queFront.second >= bridge_length) {
            que.pop();
        }
    }

    return answer;
}