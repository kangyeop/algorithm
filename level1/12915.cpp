#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int index = -1;

bool comp(string a, string b) {
    if (a[index] == b[index]) {
        return a < b;
    }
    return a[index] < b[index];
}

vector<string> solution(vector<string> strings, int n) {
    index = n;
    vector<string> answer;
    sort(strings.begin(), strings.end(), comp);
    return strings;
}