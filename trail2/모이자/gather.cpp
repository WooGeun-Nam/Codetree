#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Please write your code here.
    int n;
    cin >> n;

    vector<int> person(n);
    
    for(int i=0; i<n; i++)
    {
        cin >> person[i];
    }

    int answer = 0;

    // 첫번째 집부터 검증
    for(int i=0; i<n; i++)
    {
        int sum = 0;
        for(int j=0; j<n; j++)
        {
            // 해당 집의 인원 * 이동거리
            sum += person[j] * abs(j-i);
        }

        if(i==0) answer = sum;
        else answer = min(answer,sum);
    }

    cout << answer;

    return 0;
}