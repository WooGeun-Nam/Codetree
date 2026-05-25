#include <iostream>
using namespace std;

void func(int n, int a, bool inc)
{
    if(n < 0) return;
    
    for(int i=0; i<a; i++) cout << "* ";

    cout << endl;
    
    if(inc) a++;
    else a--;
    n--;

    if(a == 0)
    {
        cout << "* " << endl;
        inc = !inc;
        n-=2;
        a = 2;
    }

    func(n, a, inc);
}

int main() {
    // Please write your code here.
    int n;
    cin >> n;
    func(n*2, n, false);

    return 0;
}