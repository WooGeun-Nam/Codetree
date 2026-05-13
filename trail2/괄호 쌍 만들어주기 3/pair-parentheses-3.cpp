#include <iostream>
#include <string>
using namespace std;

int main() {
    // Please write your code here.
    string A;
    cin >> A;

    int count = 0; // 총 쌍 개수

    // A 순회
    for(int i=0; i<A.length(); i++)
    {
        // 현재 위치가 여는 괄호라면
        if(A[i] == '(')
        {
            // 닫는 괄호 쌍 찾기
            for(int j=i+1; j<A.length(); j++)
            {
                // 닫는 괄호라면 쌍 개수 추가
                if(A[j] == ')') count++;
            }
        }
    }

    cout << count;

    return 0;
}