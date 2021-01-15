#include <iostream>
#include <vector>

using namespace std;

int MOD = 20170805;

int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    vector<vector<pair<int, int>>> arr(m, vector<pair<int, int>>(n, pair<int, int>(0, 0)));

    arr[0][0].first = 1;
    arr[0][0].second = 1;

    for (int i = 1; i < m; i++) {
        if (city_map[i][0] != 1)
            arr[i][0].first += arr[i - 1][0].first;
    }

    for (int i = 1; i < n; i++) {
        if (city_map[0][i] != 1)
            arr[0][i].second += arr[0][i - 1].second;
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (city_map[i][j] == 1) {
                continue;
            }
            if (city_map[i - 1][j] == 2) {
                arr[i][j].first = arr[i - 1][j].first;
            } else if (!city_map[i - 1][j]) {
                arr[i][j].first = (arr[i - 1][j].first + arr[i - 1][j].second) % MOD;
            }
            if (city_map[i][j - 1] == 2) {
                arr[i][j].second = arr[i][j - 1].second;
            } else if (!city_map[i][j - 1]) {
                arr[i][j].second = (arr[i][j - 1].first + arr[i][j - 1].second) % MOD;
            }
        }
    }

    return (arr[m - 1][n - 1].first + arr[m - 1][n - 1].second) % MOD;
}