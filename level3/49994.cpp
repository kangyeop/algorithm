#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isFine(int x, int y) {
    if (y >= 0 && y <= 10 && x >= 0 && x <= 10) {
        return true;
    }
    return false;
}

int solution(string dirs) {
    int answer = 0;

    int visit[11][11][11][11] = {};

    int currentX = 5;
    int currentY = 5;
    int nextX = 0;
    int nextY = 0;

    for (int i = 0; i < dirs.size(); i++) {
        switch (dirs[i]) {
        case 'U': {
            nextY = currentY + 1;
            nextX = currentX;
            break;
        }
        case 'D': {
            nextY = currentY - 1;
            nextX = currentX;
            break;
        }
        case 'R': {
            nextX = currentX + 1;
            nextY = currentY;
            break;
        }
        case 'L': {
            nextX = currentX - 1;
            nextY = currentY;
            break;
        }
        default: {
            break;
        }
        }
        if (isFine(nextX, nextY)) {
            if (!visit[currentX][currentY][nextX][nextY]) {
                visit[currentX][currentY][nextX][nextY] = 1;
                visit[nextX][nextY][currentX][currentY] = 1;
                answer++;
            }
            currentY = nextY;
            currentX = nextX;
        }
    }
    return answer;
}