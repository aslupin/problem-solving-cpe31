#include <iostream>
using namespace std;
int main()
{

    int n, number;
    char oper;
    int sum = 0;
    cin >> n;
    cin >> number;
    sum += number;
    n--;
    do
    {

        cin >> oper;
        cin >> number;
        if (oper == '-')
            number *= -1;
        sum += number;

    } while (--n != 0);
    cout << sum;
}