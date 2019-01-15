#include <iostream>
using namespace std;
bool check_prime(int p)
{
    if (p <= 1)
    {
        return false;
    }

    int countt = 0;
    for (int i = 1; i <= p; i++)
    {
        if (p % i == 0)
        {
            countt += 1;
        }
    }
    if (countt == 2)
        return true;
    else
        return false;
}

int main()
{
    int number;
    cin >> number;
    while (1)
    {
        if (check_prime(++number))
        {
            cout << number;
            break;
        }
    }
}