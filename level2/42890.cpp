#include <map>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> Getsubset(int size) {
    vector<vector<int>> res;
    for (int i = 0; i < 1 << size; i++) {
        vector<int> vt;
        for (int j = 0; j < size; j++) {
            if (i & (1 << j)) {
                vt.push_back(j);
            }
        }
        res.push_back(vt);
    }
    return res;
}

bool Issubset(vector<int> candi, vector<int> target) {
    bool res = true;
    int firsize = (int)candi.size();
    int secsize = (int)target.size();
    if (firsize > secsize) {
        res = false;
    } else {
        int cnt = 0;
        for (int i = 0; i < firsize; i++) {
            for (int j = 0; j < secsize; j++) {
                if (candi[i] == target[j]) {
                    cnt++;
                }
            }
        }
        if (cnt == firsize) {
            res = true;
        } else {
            res = false;
        }
    }
    return res;
}

int solution(vector<vector<string>> relation) {
    int answer = 0;
    vector<vector<int>> sub = Getsubset(relation[0].size());
    vector<vector<int>> candidate;
    for (int i = 0; i < sub.size(); i++) {
        bool success = true;
        if (!candidate.empty()) {
            for (int j = 0; j < candidate.size(); j++) {
                if (Issubset(candidate[j], sub[i])) {
                    success = false;
                }
            }
        }
        if (!success) {
            continue;
        }
        map<string, int> exist;
        for (int j = 0; j < relation.size(); j++) {
            string str = string();
            for (int k = 0; k < sub[i].size(); k++) {
                str = str + relation[j][sub[i][k]];
            }
            if (exist.find(str) == exist.end()) {
                exist.insert(make_pair(str, 1));
            } else {
                success = false;
                break;
            }
        }
        if (success) {
            answer++;
            candidate.push_back(sub[i]);
        }
    }
    return answer;
}
