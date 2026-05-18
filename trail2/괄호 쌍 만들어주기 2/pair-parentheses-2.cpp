#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    string a;
    cin >> a;

    int answer = 0;

    // 최소 4칸이 필요 a.size()-3
    for(int i=0; i<a.size()-3; i++)
    {
        // 연속된 여는쌍이면
        if(a[i] == '(' && a[i+1] == '(')
        {
            // 닫는쌍 최소 2칸 필요
            for(int j=i+2; j<a.size()-1; j++)
            {
                if(a[j] == ')' && a[j+1] == ')') answer++;
            }
        }
    }

    cout << answer;

    return 0;
}