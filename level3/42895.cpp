#include <set>
#include <string>
#include <vector>

using namespace std;

int getContinuousN(int N, int cnt) {
    int result = 0;
	for (int i = 0; i < cnt; i++) {
		result = result * 10 + N;
	}
	return result;
}

int solution(int N, int number) {
    int answer = 1;

    int const min = 9;
    vector<set<int>> v(min);

    for (int i = 1; i < min; i++) {
        v[i].insert(getContinuousN(N, i));
        for (int j = 1; j < i; j++) {
            for (int k = 1; k < i; k++) {
                if (j + k == i) {
                    for (auto a : v[j]) {
                        for (auto b : v[k]) {
                            v[i].insert(a + b);
                            v[i].insert(a * b);
                            if (a > b)
                                v[i].insert(a - b);
                            if (a < b)
                                v[i].insert(b - a);
                            if (b > 0)
                                v[i].insert(a / b);
                            if (a > 0)
                                v[i].insert(b / a);
                        }
                    }
                }
            }
        }
    }
    for (int i = 1; i < min; i++) {
        for (auto j : v[i])
            if (j == number) {
                return i;
            }
    }
    return -1;
}