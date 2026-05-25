#include <iostream>
#include <vector>
using namespace std;

int lcm(vector<int> numbers, int find)
{
    bool isLcm = true;
    for(int i=0; i<numbers.size(); i++)
    {
        // 나누어떨어지지 않으면 공배수 아님
        if(find % numbers[i] != 0)
        {
            isLcm = false;
            break;
        }
    }

    if(isLcm) return find;
    else return lcm(numbers, find+1);
}

int main() {
    // Please write your code here.
    int n;
    cin >> n;

    vector<int> numbers(n);
    for(int i=0; i<n; i++)
    {
        cin >> numbers[i];
    }

    int answer = lcm(numbers, 1);

    cout << answer;

    return 0;
}