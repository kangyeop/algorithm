#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    vector<string> arr;
    for (int i = 0; i < cities.size(); i++) {
        string target = cities[i];
        transform(target.begin(), target.end(), target.begin(), ::toupper);

        auto iter = find(arr.begin(), arr.end(), target);
        if (iter != arr.end()) {
            answer++;
            arr.erase(iter);
            arr.push_back(target);
            continue;
        }
        answer += 5;
        arr.push_back(target);
        if (arr.size() > cacheSize) {
            arr.erase(arr.begin());
        }
    }
    return answer;
}