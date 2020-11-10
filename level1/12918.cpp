#include <iostream>
#include <regex>
#include <string>
#include <vector>

using namespace std;

bool solution(string s) {
    if (s.size() != 4 && s.size() != 6) {
        return false;
    }

    regex  reg("[a-z]");
    smatch m;

    if (regex_search(s, m, reg)) {
        if (m.size()) {
            return false;
        }
    }

    return true;
}