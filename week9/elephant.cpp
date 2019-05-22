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
    {
        cin >> val;
        banana[i] = 0;
    }

    for (int i = 3; i < n; i++)
    {
        cin >> val;
        oldbest = max(oldbest, banana[i - 3]);
        banana[i] = val + oldbest;
    }

    for (int i = 0; i < n; i++)
        ans = max(ans, banana[i]);

    cout << ans;
}