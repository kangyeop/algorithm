#include <queue>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    queue<pair<int, int>> que;

    int size = progresses.size();
    int date = 1;

    for (int i = 0; i < size; i++) {
        que.push(pair<int, int>(progresses[i], speeds[i]));
    }

    int count = 0;

    while (!que.empty()) {
        pair<int, int> temp = que.front();
        int progress = temp.first + temp.second * date;
        if (progress >= 100) {
            count++;
            que.pop();
            continue;
        }
        if (count) {
            answer.push_back(count);
            count = 0;
        }
        date++;
    }

    if (count) {
        answer.push_back(count);
        count = 0;
    }

    return answer;
}