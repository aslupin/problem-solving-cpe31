#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
    int n;
    int x, y, r;
    bool posinit = true, nevinit = true;
    int planet[2] = {0};
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y >> r;
        if (y > 0)
        {
            if (y - r <= 0)
            {
                cout << -1;
                return 0;
            }
            if (planet[0] > (y - r) || posinit)
            {
                planet[0] = y - r;
                posinit = false;
            }
        }
        else if (y < 0 || nevinit)
        {
            if (y + r >= 0)
            {
                cout << -1;
                return 0;
            }
            if (planet[1] < (y + r) || nevinit)
            {
                planet[1] = y + r;
                nevinit = false;
            }
        }
    }
    cout << min(abs(planet[1]), planet[0]);
}