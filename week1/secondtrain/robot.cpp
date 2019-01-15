#include <iostream>
using namespace std;
int main()
{
    int x, y;
    string walk;
    cin >> walk;
    x = y = 0;
    for (int i = 0; i < walk.length(); i++)
    {
        if (walk[i] == 'Z')
        {
            x = 0;
            y = 0;
        }
        else if (walk[i] == 'N')
        {
            y++;
        }
        else if (walk[i] == 'S')
        {
            y--;
        }
        else if (walk[i] == 'W')
        {
            x--;
        }
        else // E
        {
            x++;
        }
    }
    cout << x << " " << y;
}
