#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // Please write your code here.
    int n;
    cin >> n;

    vector<int> number(n);

    for(int i=0; i<n; i++)
    {
        cin >> number[i];
    }

    int answer = 0;

    for(int i=0; i<n; i++)
    {
        for(int j=i+2; j<n; j++)
        {
            answer = max(answer, number[i] + number[j]);
        }
    }

    cout << answer;

    return 0;
}