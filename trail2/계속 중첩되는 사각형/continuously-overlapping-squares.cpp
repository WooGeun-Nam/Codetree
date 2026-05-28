#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Please write your code here.
    int n;
    cin >> n;

    vector<vector<int>> square(250, vector<int>(250, 0));
    int indexOff = 125;

    // fasle = red/1 , true = blue/2
    bool color = false;

    // 빨간색 -> 파란색
    for(int i=0; i<n; i++)
    {
        int x1, y1;
        int x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1 += indexOff;
        y1 += indexOff;
        x2 += indexOff;
        y2 += indexOff;

        for(int j=x1; j<x2; j++)
        {
            for(int k=y1; k<y2; k++)
            {
                if(color) square[j][k] = 2;
                else square[j][k] = 1;
            }
        }

        // 색 반전
        color = !color;
    }

    int red = 0;
    int blue = 0;

    for(int i=0; i<square.size(); i++)
    {
        for(int j=0; j<square[i].size(); j++)
        {
            if(square[i][j] == 1) red++;
            else if(square[i][j] == 2) blue++;
        }
    }

    cout << blue;

    return 0;
}