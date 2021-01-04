#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<char> arr;

void makeBase(int n, int num) {
    vector<char> temp;
    while (num) {

        if (n == 10) {
            string str = to_string(num % n);
            for (auto i : str) {
                temp.push_back(i);
            }
            num /= n;
            continue;
        }
        if (n > 10 && num % n >= 10) {
            char tempChar = char('A' + (num % n - 10));
            temp.push_back(tempChar);
            num /= n;
            continue;
        }
        temp.push_back(to_string(num % n)[0]);
        num /= n;
    }
    arr.insert(arr.end(), temp.rbegin(), temp.rend());
}

string solution(int n, int t, int m, int p) {
    string answer;
    int maxSize = t * m;
    int i = 0;
    arr.push_back('0');
    while (arr.size() < maxSize) {
        makeBase(n, i);
        i++;
    }
    for (int j = 0; j < t; j++) {
        answer += arr[m * j + p - 1];
    }
    return answer;
}