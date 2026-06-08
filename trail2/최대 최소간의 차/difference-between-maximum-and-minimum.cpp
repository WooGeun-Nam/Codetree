#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // Please write your code here.
    int n, k;
    cin >> n >> k;

    vector<int> num(n);

    for(int i=0; i<n; i++) cin >> num[i];

    int answer = 1e9;

    for(int i=0; i<10000; i++)
    {
        int minNum = i;
        int maxNum = i+k;

        int count = 0;

        for(int j=0; j<n; j++)
        {
            if(num[j] < minNum) count += minNum - num[j];
            else if(num[j] > maxNum) count += num[j] - maxNum;
        }

        answer = min(answer, count);
    }

    cout << answer;

    return 0;
}