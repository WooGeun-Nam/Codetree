#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // Please write your code here.
    int n;
    cin >> n;

    vector<int> numbers;
    for(int i=0; i<n; i++)
    {
        int num;
        cin >> num;
        numbers.push_back(num);

        // 홀수일 때
        if(numbers.size() % 2!= 0)
        {
            sort(numbers.begin(), numbers.end());
            cout << numbers[numbers.size()/2] << " ";
        }
    }

    return 0;
}