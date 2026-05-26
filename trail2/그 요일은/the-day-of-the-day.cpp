#include <iostream>
#include <string>
using namespace std;

int monthDay(int m)
{
    if(m == 2) return 29;
    else if(m == 4 || m == 6 || m == 9 || m == 11) return 30;
    else return 31;
}

int getDaySum(int m, int d)
{
    int daySum = 0;
    for(int i=1; i<m; i++)
    {
        daySum += monthDay(i);
    }
    daySum += d;
    return daySum;
}

int main() {
    // Please write your code here.

    // 요일 횟수 -> day 차이 / 7
    int m1, d1;
    int m2, d2;
    string dow;

    cin >> m1 >> d1 >> m2 >> d2;
    cin >> dow;

    int day = getDaySum(m2, d2) - getDaySum(m1, d1);

    int answer = 0;

    answer += day / 7;
    int remainDay = day % 7;

    if(dow == "Mon" && remainDay >= 0) answer++;
    if(dow == "Tue" && remainDay >= 1) answer++;
    if(dow == "Wed" && remainDay >= 2) answer++;
    if(dow == "Thu" && remainDay >= 3) answer++;
    if(dow == "Fri" && remainDay >= 4) answer++;
    if(dow == "Sat" && remainDay >= 5) answer++;
    if(dow == "Sun" && remainDay >= 6) answer++;

    cout << answer;

    return 0;
}