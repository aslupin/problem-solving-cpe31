#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    if (a == b)
    {
        cout << "1/1";
    }
    else if (a > b)
    {
        for (int i = b; i >= 1; i--)
        {
            if (b % i == 0 && a % i == 0)
            {
                cout << a / i << "/" << b / i;
                break;
            }
        }
    }
    else
    {
        for (int i = a; i >= 1; i--)
        {
            if (b % i == 0 && a % i == 0)
            {
                cout << a / i << "/" << b / i;
                break;
            }
        }
    }
}