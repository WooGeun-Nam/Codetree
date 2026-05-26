#include <iostream>
#include <vector>
using namespace std;

// a 차수 to 10진수
int degreeToDemical(int a, int n)
{
    int mul = 1;
    int demical = 0;

    while(n > 0)
    {
        int num = n % 10;
        demical += num * mul;
        mul *= a;
        n /= 10;
    }

    return demical;
}

void demicalToDegree(int b, int n)
{
    vector<int> binary;

    while(n > 0)
    {
        binary.push_back(n % b);
        n /= b;
    }

    for(int i=binary.size()-1; i>=0; i--)
    {
        cout << binary[i];
    }
}

int main() {
    // Please write your code here.
    int a, b;
    cin >> a >> b;
    
    int n;
    cin >> n;

    n = degreeToDemical(a, n);
    demicalToDegree(b, n);

    return 0;
}