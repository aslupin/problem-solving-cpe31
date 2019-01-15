#include <iostream>
using namespace std;

int main()
{
    string txt;
    cin >> txt;
    for (int i = 0; i < txt.length() / 2; i++)
    {

        if (txt[i] != txt[txt.length() - i - 1])
        {
            cout << "no";
            return 0;
        }
    }
    cout << "yes";
}