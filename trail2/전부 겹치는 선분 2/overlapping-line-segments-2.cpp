#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Please write your code here.
    int n;

    cin >> n;

    vector<vector<int>> line(n, vector<int>(2,0));

    for(int i=0; i<n; i++)
    {
        cin >> line[i][0] >> line[i][1];
    }

    bool answer = false;

    // i 선분 제외시 가능한지 여부
    for(int i=0; i<n; i++)
    {
        int maxStart = 1;
        int minEnd = 100;

        for(int j=0; j<n; j++)
        {
            if(i == j) continue;

            maxStart = max(maxStart, line[j][0]);
            minEnd = min(minEnd, line[j][1]);
        }

        // 겹치는지 여부 확인
        if(maxStart <= minEnd)
        {
            answer = true;
            break;
        }
    }

    if(answer) cout << "Yes";
    else cout << "No";

    return 0;
}