#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Please write your code here.
    int n, m;
    cin >> n >> m;
    
    vector<vector<char>> grid(n, vector<char>(m));

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> grid[i][j];
        }
    }

    // 8방향 {상, 하, 좌, 우, 좌상, 우상, 좌하, 우하}
    int dx[8] = {0, 0, -1, 1, -1, 1, -1, 1};
    int dy[8] = {-1, 1, 0, 0, -1, -1, 1, 1};

    int answer = 0;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            // 현재 위치가 L 이라면 EE 찾기
            if(grid[i][j] == 'L')
            {
                for(int k=0; k<8; k++)
                {
                    int ex1 = j + dx[k] * 1;
                    int ey1 = i + dy[k] * 1;
                    int ex2 = j + dx[k] * 2;
                    int ey2 = i + dy[k] * 2;
                    
                    // E 두개가 그리드 안에 있는지 확인
                    if(ex1 >= 0 && ex1 < m && ey1 >= 0 && ey1 < n
                        && ex2 >= 0 && ex2 < m && ey2 >= 0 && ey2 < n)
                    {
                        // 그리드 안에 있고 두 문자가 E 라면 정답
                        if(grid[ey1][ex1] == 'E' && grid[ey2][ex2] == 'E') answer++;
                    }
                }
            }
        }
    }

    cout << answer;

    return 0;
}