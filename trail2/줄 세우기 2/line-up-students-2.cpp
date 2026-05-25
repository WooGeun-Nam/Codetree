#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // Please write your code here.

    int n;
    cin >> n;

    vector<vector<int>> student(n, vector<int>(3));

    for(int i=0; i<n; i++)
    {
        // h >> w
        cin >> student[i][0] >> student[i][1];
        student[i][2] = i+1;
    }

    sort(student.begin(), student.end(), [](const vector<int>& a, const vector<int>& b)
    {
        // 키가 같다면
        if(a[0] == b[0])
        {
            return a[1] > b[1];
        }

        return a[0] < b[0];
    });

    for(int i=0; i<n; i++)
    {
        cout << student[i][0] << " " << student[i][1] << " " << student[i][2] << endl;
    }

    return 0;
}