#include <iostream>
using namespace std;
int main()
{
    int gift, n;
    int sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> gift;
        if (gift > 0)
            sum += gift;
    }
    cout << sum;
}