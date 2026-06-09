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

    int minNumber = *min_element(num.begin(), num.end());
    int maxNumber = *max_element(num.begin(), num.end());

    for(int i=minNumber; i<=maxNumber-k; i++)
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
