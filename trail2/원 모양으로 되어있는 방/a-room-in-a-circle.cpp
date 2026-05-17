#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    // Please write your code here.

    int n;
    cin >> n;

    vector<int> room(n);
    for(int i=0; i<n; i++)
    {
        cin >> room[i];
    }

    int minMove = 0;

    // 첫번째 방부터 이동 횟수 계산
    for(int i=0; i<n; i++)
    {
        // 이동 횟수
        int move = 0;
        int current = i;
        int distance = 0;

        // 방의 개수만큼만 반복하도록 설정
        for(int step=0; step<n; step++)
        {
            move += room[current] * distance;

            // 시계 반대방향 이동
            if(current+1 >= n) current = 0;
            else current++;

            distance++;
        }

        if(i == 0) minMove = move;
        else 
        {
            minMove = min(minMove, move);
        }
    }

    cout << minMove;

    return 0;
}