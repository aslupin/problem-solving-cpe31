#include <iostream>
using namespace std;
int main()
{
    char txt[100];
    char upper[100];
    cin >> txt;
    for (int i = 0; txt[i] != '\0'; i++)
    {
        if ((int)txt[i] >= 97 && (int)txt[i] <= 122)
        {
            int diff = (int)txt[i] - 32;
            upper[i] = (char)diff;
        }
        else
        {
            upper[i] = txt[i];
        }
    }
    cout << upper;
}