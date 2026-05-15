#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    // Please write your code here.
    string a;
    cin >> a;

    int answer = 0;

    // 모든 자리를 하나씩 바꿔보며 확인
    for(int i=0; i<a.length(); i++)
    {
        // i번째 자리 바꾸기 (0은 1로, 1은 0으로)
        if(a[i] == '0') a[i] = '1';
        else a[i] = '0';

        // 현재 이진수 문자열을 십진수로 변환
        int current_val = 0;
        for(int j=0; j<a.length(); j++)
        {
            current_val = current_val * 2 + (a[j] - '0');
        }

        // 가능한 N 중 최댓값 저장
        if(i == 0) answer = current_val;
        else answer = max(answer, current_val);

        // 다음 위치를 확인하기 위해 다시 원래 상태로 복구
        if(a[i] == '0') a[i] = '1';
        else a[i] = '0';
    }

    cout << answer;

    return 0;
}