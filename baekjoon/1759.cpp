#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

vector<char> vowel = { 'a', 'e', 'i', 'o', 'u' };
set<string> answer;
vector<bool> visit;
int n, m;

void dfs(string str, string ans, int startItem, int v, int s) {
    if (ans.size() == n) {
        if (s >= 2 && v >= 1) {
            answer.insert(ans);
        }
        return;
    }

    for (int i = startItem; i < m - n + ans.size() + 1; i++) {
        if (!visit[i]) {
            visit[i] = true;
            if (find(vowel.begin(), vowel.end(), str[i]) != vowel.end()) {
                dfs(str, ans + str[i], i + 1, v + 1, s);
            } else {
                dfs(str, ans + str[i], i + 1, v, s + 1);
            }
            visit[i] = false;
        }
    }
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;

    string str;

    for (int i = 0; i < m; i++) {
        char temp;
        cin >> temp;
        str += temp;
    }

    sort(str.begin(), str.end());

    for (int i = 0; i < m - n + 1; i++) {
        string ans;
        visit.clear();
        visit.assign(m, false);
        ans += str[i];
        visit[i] = true;

        if (find(vowel.begin(), vowel.end(), str[i]) != vowel.end()) {
            dfs(str, ans, i + 1, 1, 0);
        } else {
            dfs(str, ans, i + 1, 0, 1);
        }
        }

    for (auto i = answer.begin(); i != answer.end(); i++) {
        cout << *i << endl;
    }

    return 0;
}