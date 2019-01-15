#include <iostream>
#include <stdlib.h>
using namespace std;
int abs(int x)
{
    if (x < 0)
        return -x;
    return x;
}
int main()
{
    string walk;
    int miss;
    int x = 0, y = 0;
    cin >> walk;
    cin >> miss;
    int n = 0, s = 0, w = 0, e = 0;
    for (int i = 0; i < walk.length(); i++)
    {
        if (walk[i] == 'N')
        {
            n++;
            y++;
        }
        else if (walk[i] == 'S')
        {
            s++;
            y--;
        }
        else if (walk[i] == 'W')
        {
            w++;
            x--;
        }
        else
        {
            e++;
            x++;
        }
    }
    char miss1, miss2;
    if (x > 0 && y > 0)
    {
        miss1 = 'S';
        miss2 = 'W';
    }
    else if (x < 0 && y > 0)
    {
        miss1 = 'S';
        miss2 = 'E';
    }
    else if (x < 0 && y < 0)
    {
        miss1 = 'N';
        miss2 = 'E';
    }
    else
    {
        miss1 = 'N';
        miss2 = 'W';
    }
    if (miss1 == 'N')
    {
        while (n != 0 && miss != 0)
        {
            y--;
            n--;
            miss--;
        }
    }
    else if (miss1 == 'S')
    {
        while (s != 0 && miss != 0)
        {
            y++;
            s--;
            miss--;
        }
    }
    if (miss2 == 'W')
    {
        while (w != 0 && miss != 0)
        {
            x++;
            w--;
            miss--;
        }
    }
    else if (miss2 == 'E')
    {
        while (e != 0 && miss != 0)
        {
            x--;
            e--;
            miss--;
        }
    }
    int ans = abs(x) + abs(y);
    ans -= miss;
    cout << ans * 2;
}
