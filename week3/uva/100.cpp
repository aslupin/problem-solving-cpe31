#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int sol(int n, int count = 0)
{
    while (1)
    {
        count++;
        if (n == 1)
        {
            return count;
        }
        else
        {
            if (n % 2 == 1)
                n = 3 * n + 1;
            else
                n = n / 2;
        }
    }
}
int main()
{
    int a, b;
    typedef pair<int, int> ii;
    typedef pair<ii, int> iii;
    vector<iii> viii;
    // cin >> a;
    // cout << sol(a);
    while (cin >> a >> b)
    {
        int less = min(a, b);
        int maxie = max(a, b);
        int max_cycle = sol(less);
        for (int i = less + 1; i <= maxie; i++)
        {
            int tmp = sol(i);
            if (tmp > max_cycle)
            {
                max_cycle = tmp;
            }
        }
        viii.push_back(make_pair(make_pair(a, b), max_cycle));
        // cout << sol(a) << " " << sol(b) << endl;
    }
    for (vector<iii>::iterator itr = viii.begin(); itr != viii.end(); itr++)
    {
        cout << itr->first.first << " " << itr->first.second << " " << itr->second << endl;
    }
}