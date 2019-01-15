#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    // for (int i = 1; i <= n; i++)
    // {
    for (int j = 1; j <= n; j++)
    {
        for (int space = 1; space <= n - j; space++)
        {
            cout << " ";
        }
        for (int star = 1; star <= j; star++)
        {
            cout << "*";
        }
        cout << endl;
    }
    // }
}