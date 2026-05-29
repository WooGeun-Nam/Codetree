#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // Please write your code here.
    int n, t;
    cin >> n >> t;

    int answer = 0;
    int cnt = 0;

    for(int i=0; i<n; i++)
    {
        int num;
        cin >> num;

        if(num > t)
        {
            cnt++;
            answer = max(answer, cnt);
        }
        else
        {
            cnt = 0;
        }
    }

    cout << answer;

    return 0;
}