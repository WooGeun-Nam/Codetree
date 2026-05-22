#include <iostream>
using namespace std;

void func(int& a, int& b)
{
    if(a > b)
    {
        a *= 2;
        b += 10;
    }
    else
    {
        a += 10;
        b *= 2;
    }
}

int main() {
    // Please write your code here.
    int a, b;
    cin >> a >> b;

    func(a, b);

    cout << a << " " << b;

    return 0;
}