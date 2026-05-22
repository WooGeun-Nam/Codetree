#include <iostream>
#include <string>
using namespace std;

// 윤년체크
bool yearCheck(int y)
{
    if(y % (4 * 100) == 0) return true;
    if(y % 100 == 0) return false;
    if(y % 4 == 0) return true;
    return false;
}

// 월별 일 수 체크
int monthCheck(int y, int m)
{
    if(m == 2)
    {
        if(yearCheck(y)) return 29;
        else return 28;
    }
    if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
    {
        return 31;
    }
    if(m == 4 || m == 6 || m == 9 || m == 11)
    {
        return 30;
    }
}

string seasonCheck(int y, int m, int d)
{
    int vaildMonth = monthCheck(y, m);

    // 정상 월 범위 안인지 확인
    if(d <= vaildMonth)
    {
        if(m >= 3 && m <= 5) return "Spring";
        else if(m >= 6 && m <= 8) return "Summer";
        else if(m >= 9 && m <= 11) return "Fall";
        else return "Winter";
    }
    
    // 정상범위가 아니라면 없는 날
    return "-1";
}

int main() 
{
    // Please write your code here.
    int y, m, d;
    cin >> y >> m >> d;

    cout << seasonCheck(y, m, d);

    return 0;
}