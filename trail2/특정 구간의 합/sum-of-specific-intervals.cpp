#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Please write your code here.
    int n, m;
    
    cin >> n >> m;

    vector<int> numbers(n);

    for(int i=0; i<n; i++)
    {
        cin >> numbers[i];
    }

    for(int i=0; i<m; i++)
    {
        int sum = 0;

        int a1, a2;
        cin >> a1 >> a2;

        for(int j=a1-1; j<=a2-1; j++)
        {
            sum += numbers[j];
        }

        cout << sum << endl;
    }

    return 0;
}