#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Please write your code here.
    vector<vector<int>> grid(19, vector<int>(19,0));

    int answer = 0;
    pair<int, int> pos;

    for(int i=0; i<19; i++)
    {
        for(int j=0; j<19; j++)
        {
            cin >> grid[i][j];
        }
    }

    // 왼쪽 위부터 순차대로 확인하니 오른쪽, 아래 방향만 검증
    for(int i=0; i<19; i++)
    {
        bool win = false;
        for(int j=0; j<19; j++)
        {
            int check = grid[i][j];

            // 좌표에 돌이 놓여져 있으면 확인
            if(check != 0)
            {
                // 가로 검증
                if (j + 4 < 19) {
                    for (int k = j + 1; k < j + 5; k++) {
                        if (grid[i][k] != check) break;
                        if (k == j + 4) {
                            win = true;
                            answer = check;
                            pos.first = i + 1;
                            pos.second = (j + 2) + 1; 
                        }
                    }
                }

                // 세로 검증
                if (i + 4 < 19 && !win) { 
                    for (int k = i + 1; k < i + 5; k++) {
                        if (grid[k][j] != check) break;
                        if (k == i + 4) {
                            win = true;
                            answer = check;
                            pos.first = (i + 2) + 1;
                            pos.second = j + 1;
                        }
                    }
                }

                // 3. 우하향 대각선 검증
                if (i + 4 < 19 && j + 4 < 19 && !win) {
                    for (int k = 1; k < 5; k++) {
                        if (grid[i + k][j + k] != check) break;
                        if (k == 4) {
                            win = true;
                            answer = check;
                            pos.first = (i + 2) + 1;
                            pos.second = (j + 2) + 1;
                        }
                    }
                }

                // 4. 우상향 대각선 검증
                if (i - 4 >= 0 && j + 4 < 19 && !win) {
                    for (int k = 1; k < 5; k++) {
                        if (grid[i - k][j + k] != check) break;
                        if (k == 4) {
                            win = true;
                            answer = check;
                            pos.first = (i - 2) + 1;
                            pos.second = (j + 2) + 1;
                        }
                    }
                }
            }

            if(win) break;
        }

        if(win) break;
    }

    cout << answer << endl;
    if(answer > 0) cout << pos.first << " " << pos.second;

    return 0;
}