#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    // Please write your code here.
    int n, m;

    cin >> n >> m;

    // 최대공약수
    int gcd = 0;

    // 최소공배수
    int lcm = 0;

    // 최대공약수 먼저 구하기
    for(int i=1; i<=min(n,m); i++)
    {
        // 두 수로 나누어 떨어지면 최대공약수
        if(n % i == 0 && m % i == 0)
        {
            gcd = i;   
        }
    }

    lcm = n * m / gcd;

    cout << lcm;

    return 0;
}