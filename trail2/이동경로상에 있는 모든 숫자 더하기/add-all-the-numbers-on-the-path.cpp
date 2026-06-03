#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Please write your code here.
    int n, t;
    cin >> n >> t;

    string order;
    cin >> order;

    vector<vector<int>> grid(n, vector<int>(n,0));

    // 격자 값 입력
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> grid[i][j];
        }
    }

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    int dir = 0;

    int posX = n/2;
    int posY = n/2;
    int answer = grid[posX][posY];

    // 명령 수행
    for(int i=0; i<t; i++)
    {
        char next = order[i];

        if(next == 'R')
        {
            if(dir == 3) dir = 0;
            else dir++;
        }
        else if(next == 'L')
        {
            if(dir == 0) dir = 3;
            else dir--;
        }
        // Front
        else
        {
            int nextPosX = posX + dx[dir];
            int nextPosY = posY + dy[dir];

            // 다음 위치가 격자 안이면
            if(nextPosX >= 0 && nextPosX < n && nextPosY >= 0 && nextPosY < n)
            {
                // 현재 위치 변경
                posX = nextPosX;
                posY = nextPosY;

                // 값 추가
                answer += grid[posX][posY];
            }
        }
    }

    cout << answer;

    return 0;
}