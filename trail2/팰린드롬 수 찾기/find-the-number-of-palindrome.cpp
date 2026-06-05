#include <iostream>
#include <string>
using namespace std;

bool checkNumber(int num)
{
    string strNum = to_string(num);

    for(int i=0; i<strNum.size()/2; i++)
    {
        if(strNum[i] != strNum[strNum.size() - 1 - i]) return false;
    }

    return true;
}

int main() {
    // Please write your code here.
    int x, y;
    cin >> x >> y;

    int answer = 0;

    for(int i=x; i<=y; i++)
    {
        if(checkNumber(i)) answer++;
    }

    cout << answer;

    return 0;
}