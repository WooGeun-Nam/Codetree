#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Please write your code here.
    int r, c;
    cin >> r >> c;

    vector<vector<char>> grid(r, vector<char>(c));

    // 격자 정보 입력 받기
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
        {
            cin >> grid[i][j];
        }
    }

    int answer = 0;

    // 첫 번째 점프 지점 (i, j) 찾기
    for(int i=1; i<r; i++)
    {
        for(int j=1; j<c; j++)
        {
            // 첫 번째 점프: 시작점(0,0)과 색이 달라야 함
            if(grid[i][j] != grid[0][0])
            {
                // 두 번째 점프 지점 (k, l) 찾기
                // k는 i보다 커야 하고, 마지막 행(r-1)보다는 작아야 함
                for(int k=i+1; k<r-1; k++)
                {
                    for(int l=j+1; l<c-1; l++)
                    {
                        // 두 번째 점프: 첫 번째 지점(i,j)과 색이 달라야 함
                        // 세 번째 점프: 두 번째 지점(k,l)과 도착점(r-1,c-1)의 색이 달라야 함
                        if(grid[k][l] != grid[i][j] && grid[k][l] != grid[r-1][c-1])
                        {
                            answer++;
                        }
                    }
                }
            }
        }
    }

    cout << answer;

    return 0;
}