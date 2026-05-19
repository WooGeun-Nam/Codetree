#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // Please write your code here.
    int n;
    cin >> n;

    vector<int> numbers(n);
    for(int i=0; i<n; i++)
    {
        cin >> numbers[i];
    }

    int answer = -1;

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            for(int k=j+1; k<n; k++)
            {
                bool carry = false;

                int num1 = numbers[i];
                int num2 = numbers[j];
                int num3 = numbers[k];

                while(num1 > 0 || num2 > 0 || num3 > 0)
                {
                    // 자리수 합
                    int sum = num1 % 10 + num2 % 10 + num3 % 10;

                    // carry 발생 시
                    if(sum > 9)
                    {
                        carry = true;
                        break;
                    }

                    num1 /= 10;
                    num2 /= 10;
                    num3 /= 10;
                }

                if(!carry) answer = max(answer, numbers[i] + numbers[j] + numbers[k]);
            }
        }
    }

    cout << answer;

    return 0;
}