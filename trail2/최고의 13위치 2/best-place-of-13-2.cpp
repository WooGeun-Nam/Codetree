#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Please write your code here.
    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n, 0));

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> grid[i][j];
        }
    }

    int answer = 0;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n-2; j++)
        {
            // 첫번째 격자
            int firstSum = grid[i][j] + grid[i][j+1] + grid[i][j+2];
            
            // 두번째 격자 찾기
            for(int i2=0; i2<n; i2++)
            {
                for(int j2=0; j2<n-2; j2++)
                {
                    // 같은 라인에 있을때는 첫번째 격자와 겹치지 않게
                    if (i == i2 && !(j2 >= j + 3 || j2 + 3 <= j)) continue;
                    int secondSum = grid[i2][j2] + grid[i2][j2+1] + grid[i2][j2+2];

                    answer = max(answer, firstSum + secondSum);
                }
            }
        }
    }

    cout << answer;

    return 0;
}