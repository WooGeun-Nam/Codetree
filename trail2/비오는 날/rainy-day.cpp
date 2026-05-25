#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // Please write your code here.
    int n;
    cin >> n;

    vector<vector<string>> weather(n, vector<string>(3));

    for(int i=0; i<n; i++)
    {
        cin >> weather[i][0] >> weather[i][1] >> weather[i][2];
    }

    sort(weather.begin(), weather.end(), [](const vector<string>& a, const vector<string>& b)
    {
        bool a_rain = (a[2] == "Rain");
        bool b_rain = (b[2] == "Rain");

        if(a_rain != b_rain)
        {
            return a_rain;
        }

        return a[0] < b[0];
    });
    
    cout << weather[0][0] << " " << weather[0][1] << " " << weather[0][2];

    return 0;
}