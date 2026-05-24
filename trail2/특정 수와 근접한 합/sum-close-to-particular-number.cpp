#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int n, s;

    cin >> n >> s;

    vector<int> numbers(n);

    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    // Please write your code here.

    int answer = INT_MAX;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(j == i) continue;

            int t = 0;
            // i, j 두 수 선택
            for(int k=0; k<n; k++)
            {
                // 선택된 두 수 제외
                if(k == i || k == j) continue;
                t += numbers[k];
            }
            t = abs(t - s);

            answer = min(answer, t);
        }
    }

    cout << answer;

    return 0;
}