#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // Please write your code here.
    int n, m;

    cin >> n >> m;

    // 시간별 위치
    vector<int> a;
    vector<int> b;

    // a 이동
    for(int i=0; i<n; i++)
    {
        int v, t;
        cin >> v >> t;
        for(int j = 0; j < t; j++) {
            if (a.empty()) a.push_back(v);       // 맨 처음 1초일 때
            else a.push_back(a.back() + v);     // 누적 계산
        }
    }

    // b 이동
    for(int i=0; i<m; i++)
    {
        int v, t;
        cin >> v >> t;
        for(int j = 0; j < t; j++) {
            if (b.empty()) b.push_back(v);       // 맨 처음 1초일 때
            else b.push_back(b.back() + v);     // 누적 계산
        }
    }

    int distance = min(a.size(), b.size());
    int top = 3; // a = 1; b = 2, a,b = 3
    int answer = 0;

    for(int i=0; i<distance; i++)
    {
        int curTop = 0;
        if(a[i] > b[i]) curTop = 1;
        if(a[i] < b[i]) curTop = 2;
        if(a[i] == b[i]) curTop = 3;

        // 순위 변동
        if(top != curTop)
        {
            answer++;
            top = curTop;
        }
    }

    cout << answer;

    return 0;
}