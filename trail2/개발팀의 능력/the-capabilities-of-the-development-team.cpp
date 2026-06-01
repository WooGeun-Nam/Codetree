#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

int main() {
    // Please write your code here.
    vector<int> abil(5);

    for(int i=0; i<5; i++)
    {
        cin >> abil[i];
    }

    int sumAbil = accumulate(abil.begin(), abil.end(), 0);
    int diff = 1000000;

    for(int i = 0; i < 5; i++) {
        for(int j = i + 1; j < 5; j++) {
            for(int k = 0; k < 5; k++) {

                if(k == i || k == j) continue;

                int team1 = abil[i] + abil[j];
                int team2 = abil[k];
                int team3 = sumAbil - team1 - team2;

                // 세팀의 능력치가 달라야 함
                if(team1 != team2 && team2 != team3 && team1 != team3) {
                    // 세 값중 최대 값, 최소 값 추출
                    int max_val = max({team1, team2, team3});
                    int min_val = min({team1, team2, team3});
                    
                    diff = min(diff, max_val - min_val);
                }
            }
        }
    }

    // 못찾았다면 -1
    if (diff == 1000000) {
        cout << -1;
    } else {
        cout << diff;
    }

    return 0;
}