#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // Please write your code here.
    int n;
    cin >> n;
    
    vector<vector<int>> grid(n, vector<int>(n,0));

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> grid[i][j];
        }
    }

    // 1*3 크기의 격자의 1의 개수 찾기
    int answer = 0;
    int currentGrid = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            // 검증할 격자가 grid 영역 안 이라면 찾기
            if(j+2 < n)
            {
                currentGrid = grid[i][j] + grid[i][j+1] + grid[i][j+2];
                // 최댓값 정답 저장
                answer = max(answer, currentGrid);
            }
        }
    }

    cout << answer;

    return 0;
}