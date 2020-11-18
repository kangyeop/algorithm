#include <string>
#include <vector>

using namespace std;

string str_day[]   = { "FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU" };
int    month_day[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

string solution(int a, int b) {
    // string answer = "";
    int day = 0;
    for (int i = 0; i < a - 1; i++) {
        day += month_day[i];
    }
    day += b - 1;

    int index = day % 7;

    return str_day[index];
}