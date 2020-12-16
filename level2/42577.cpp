#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool comp(string a, string b) { return a.size() < b.size(); }

bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end(), comp);
    for (int i = 0; i < phone_book.size() - 1; i++) {

        string str = phone_book[i];
        for (int j = i + 1; j < phone_book.size(); j++) {
            if (str == phone_book[j].substr(0, str.size())) {
                return false;
            }
        }
    }
    return answer;
}