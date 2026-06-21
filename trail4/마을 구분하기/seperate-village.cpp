#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int n;
int grid[25][25];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    // Please write your code here.

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    vector<int> answer;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            // 해당 영역이 사람이라면 탐색 시작
            if(grid[i][j] == 1)
            {
                stack<pair<int, int>> s;
                s.push({i, j});

                int person = 0;

                while(!s.empty())
                {
                    pair<int, int> cur = s.top();
                    s.pop();

                    int x = cur.first;
                    int y = cur.second;
                    
                    // 방문한 곳이라면 pass
                    if(grid[x][y] == 2) continue;
                    
                    // 방문처리
                    grid[x][y] = 2;
                    person++;

                    for(int k=0; k<4; k++)
                    {
                        int nextX = x + dx[k];
                        int nextY = y + dy[k];
                        // grid 범위 안에 사람이라면 스택추가
                        if(nextX >= 0 && nextX < n
                            && nextY >= 0 && nextY < n
                            && grid[nextX][nextY] == 1)
                        {
                            s.push({nextX, nextY});
                        }
                    }
                }

                // 정답 추가
                answer.push_back(person);
            }
        }
    }

    sort(answer.begin(), answer.end());

    cout << answer.size() << endl;

    for(int i=0; i<answer.size(); i++)
    {
        cout << answer[i] << endl;
    }

    return 0;
}
