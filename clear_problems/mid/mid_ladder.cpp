#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int dice, pos_curr = 0;
    int table[n + 1];
    table[0] = 0;
    for (int i = 1; i <= n; i++)
        cin >> table[i];
    for (int i = 0; i < m; i++)
    {
        cin >> dice;
        if (dice + pos_curr <= n && dice + pos_curr >= 0)
            pos_curr += table[dice + pos_curr] + dice;
        else if (dice + pos_curr >= n)
        {
            pos_curr = n;
            break;
        }
        else if (dice + pos_curr <= 0)
            pos_curr = 0;
    }
    cout << pos_curr;
}