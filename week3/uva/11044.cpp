#include <iostream>
#include <list>
using namespace std;
int main()
{
    list<int> ans;
    int n;
    cin >> n;
    int loch[n][2];
    for (int i = 0; i < n; i++)
    {

        cin >> loch[i][0] >> loch[i][1];

        int n, m;

        int row = 0, col = 0;
        n = loch[i][0] - 2;
        m = loch[i][1] - 2;

        row = n / 3;
        if (n % 3 != 0)
            row += 1;

        if (m > 3)
        {
            col = m / 3;
            if (m % 3 != 0)
                col += 1;
        }

        ans.push_back(col * row);
    }
    for (list<int>::iterator itr = ans.begin(); itr != ans.end(); itr++)
        cout << *itr << endl;
}