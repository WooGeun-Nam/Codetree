#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // Please write your code here.
    int n, b;
    cin >> n >> b;

    vector<int> p(n);
    vector<int> s(n);

    for(int i=0; i<n; i++)
    {
        cin >> p[i] >> s[i];
    }

    int answer = 0;

    for(int i=0; i<n; i++)
    {
        vector<int> price;

        // 계산될 요금 입력
        for(int j=0; j<n; j++)
        {
            if(i==j) price.push_back(p[j]/2 + s[j]);
            else price.push_back(p[j] + s[j]);
        }

        sort(price.begin(), price.end());
        int money = b;
        int count = 0;

        for(int j=0; j<price.size(); j++)
        {
            // 선물 가능하면 차감
            if(price[j] <= money)
            {
                money -= price[j];
                count++;
            }
            // 초과시 선물불가 조기종료
            else break;
        }

        answer = max(answer, count);
    }

    cout << answer;

    return 0;
}