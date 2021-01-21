#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

vector<string> userId;
vector<string> bannedId;
vector<bool> visit;
set<set<string>> arr;

void dfs(int x, set<string> ans) {
    if (x == bannedId.size()) {
        arr.insert(ans);
        return;
    }
    for (int j = 0; j < userId.size(); j++) {
        if (!visit[j]) {
            if (bannedId[x].size() != userId[j].size()) {
                continue;
            }
            bool isSame = true;
            for (int k = 0; k < userId[j].size(); k++) {
                if (bannedId[x][k] != '*' && bannedId[x][k] != userId[j][k]) {
                    isSame = false;
                    break;
                }
            }
            if (isSame) {
                visit[j] = true;
                set<string> temp = ans;
                temp.insert(userId[j]);
                dfs(x + 1, temp);
                visit[j] = false;
            }
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    userId = user_id;
    bannedId = banned_id;
    visit.assign(user_id.size(), false);
    dfs(0, set<string> {});

    return arr.size();
}