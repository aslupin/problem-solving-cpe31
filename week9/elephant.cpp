#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n, val;
    cin >> n;

    int banana[n];
    int oldbest = 0;
    int ans = 0;
    for (int i = 0; i < 3; i++)
        banana[i] = 0;

    for (int i = 3; i < n; i++)
    {
        cin >> val;

        if (i == 3)
            banana[i] = val;
        else
        {
            oldbest = max(max(max(oldbest, banana[i - 3]), banana[i - 2]), banana[i - 1]);
            banana[i] = val + oldbest;
        }

        ans = max(banana[i], ans);
    }
    cout << ans;
}