#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    // Please write your code here.
    int n;
    cin >> n;

    vector<pair<int, string>> com(n);

    for(int i=0; i<n; i++)
    {
        cin >> com[i].first >> com[i].second;
    }

    vector<int> fill(200000, 0);
    int index = 100000;

    for(int i=0; i<n; i++)
    {
        int x = com[i].first;
        string dir = com[i].second;

        bool dirBool = false;
        if(dir == "R") dirBool = true;

        for(int j=0; j<x; j++)
        {
            // 검은색 : 1, 흰색 : -1
            if(dirBool) 
            {
                fill[index] = 1;
                index++;
            }
            else 
            {
                fill[index] = -1;
                index--;
            }
        }

        if(dirBool) index--;
        else index++;
    }

    int white = 0;
    int black = 0;

    for(int i=0; i<fill.size(); i++)
    {
        if(fill[i] == -1) white++;
        if(fill[i] == 1) black++;
    }

    cout << white << " " << black;

    return 0;
}