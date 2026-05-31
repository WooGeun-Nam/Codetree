#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // Please write your code here.
    int n, h, t;
    cin >> n >> h >> t;

    vector<int> farm(n);

    for(int i=0; i<n; i++)
    {
        cin >> farm[i];
    }

    int answer = 10000; 

    for(int i=0; i<=n-t; i++)
    {
        // 구간별 총 비용
        int sum = 0;
        for(int j=i; j<i+t; j++)
        {
            sum += abs(farm[j] - h);
        }

        answer = min(answer, sum);
    }

    cout << answer;

    return 0;
}