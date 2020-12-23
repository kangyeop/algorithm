#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int num = brown + yellow;

    int k = sqrt(num);

    for (int i = 3; i <= k; i++) {
        if (!(num % i)) {
            // 가운데를 둘러싸고 있기 때문에 위 아래로 각각 한칸씩 늘어나서 -2, 양옆으로 한칸씩 늘어나서 -2 
            if ((i - 2) * (num / i - 2) == yellow) {
                if (i > (num / i)) {
                    answer.push_back(i);
                    answer.push_back(num / i);
                } else {
                    answer.push_back(num / i);
                    answer.push_back(i);
                }
            }
        }
    }

    return answer;
}