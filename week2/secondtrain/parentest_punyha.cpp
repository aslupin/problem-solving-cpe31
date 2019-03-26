#include <iostream>

using namespace std;

bool isBalance(char n[], int size)
{
    int i, count = 0;
    for (i = 0; i < size; i++)
    {
        if (n[i] == '{' || n[i] == '[' || n[i] == '(')
        {
            count++;
        }
        else if (n[i] == '}' || n[i] == ']' || n[i] == ')')
        {
            count--;
        }
        else
            return -1;
    }
    if (count == 0)
        return true;
    else
        return false;
}
int main()
{
    int T;
    cin >> T;
    char n[1000];
    for (int i = 0; i < T; i++)
    {
        cin >> n;
        int size = strlen(n);
        bool result = isBalance(n, size);
        if (result == true)
            cout << "yes";
        else
            cout << "no";
    }

    return 0;
}