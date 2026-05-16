#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    // Please write your code here.
    int n;
    cin >> n;

    vector<pair<int, int>> checkPoint(n);

    for(int i=0; i<n; i++)
    {
        cin >> checkPoint[i].first >> checkPoint[i].second;
    }

    int distance = 0;

    // 전체 이동거리
    for(int i=0; i<n-1; i++)
    {
        distance += abs(checkPoint[i].first - checkPoint[i+1].first) + abs(checkPoint[i].second - checkPoint[i+1].second);
    }

    // 줄어든 거리 중 가장 큰 값
    int maxDistance = 0;

    // 최적거리 구하기 1,N 제외
    for(int i=1; i<n-1; i++)
    {
        int origin = 0;
        int taxi = 0;
        int reduce = 0;
        
        // 기존 동선
        origin = (abs(checkPoint[i-1].first - checkPoint[i].first) + abs(checkPoint[i-1].second - checkPoint[i].second))
                    + (abs(checkPoint[i].first - checkPoint[i+1].first) + abs(checkPoint[i].second - checkPoint[i+1].second));

        // 택시 탑승 동선
        taxi = abs(checkPoint[i-1].first - checkPoint[i+1].first) + abs(checkPoint[i-1].second - checkPoint[i+1].second);

        // 동선 차이 값 -> 클수록 이득이 큼
        reduce = origin - taxi;

        maxDistance = max(maxDistance, reduce);
    }
    
    // 정답 : 전체 거리 + 최대 감소 거리
    int answer = distance - maxDistance;

    cout << answer;

    return 0;
}