#include <iostream>

using namespace std;

int X;

int main() {
    // Please write your code here.
    int x;
    cin >> x;

    int currentTime = 1;
    while (true)
    {
        int maxDist = 0;

        // 홀수 시간
        if(currentTime % 2 != 0)
        {
            int k = (currentTime + 1) / 2;
            maxDist = k * k;
        }
        // 짝수 시간
        else
        {
            int k = currentTime / 2;
            maxDist = k * (k + 1);
        }

        // 최대거리 이상이면 조기 종료
        if(maxDist >= x)
        {
            cout << currentTime;
            break;
        }
        
        currentTime++;
    }

    return 0;
}