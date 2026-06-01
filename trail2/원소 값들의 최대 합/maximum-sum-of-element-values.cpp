#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // Please write your code here.
    int n, m;
    cin >> n >> m;

    vector<int> nums(n);

    for(int i=0; i<n; i++)
    {
        cin >> nums[i];
    }

    int answer = 0;

    for(int i=0; i<n; i++)
    {
        int sum = nums[i];
        int pos = nums[i] - 1;
        for(int j=0; j<m-1; j++)
        {
            sum = sum + nums[pos];
            pos = nums[pos] - 1;
        }

        answer = max(answer, sum);
    }

    cout << answer;

    return 0;
}