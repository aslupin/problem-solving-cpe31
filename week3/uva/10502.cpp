#include <iostream>
#include <list>
using namespace std;
int main()
{
    list<int> ans;
    while (1)
    {

        int n, m;
        cin >> n;
        if (n == 0)
            break;
        cin >> m;

        string board[n];
        for (int i = 0; i < n; i++)
        {
            cin >> board[i];
        }
        int counting = 0;

        // row = col
        for (int row = 0; row < n; row++)
        {

            for (int len = 1; len <= m; len++)
            {

                for (int ch = 0; ch < m; ch++)
                {

                    int accept = 1;
                    if (ch + len <= m)
                    {

                        for (int roop = 0; roop < len; roop++)
                        {

                            if (board[row][ch + roop] != '1')
                            {

                                accept = 0;
                                break;
                            }
                        }
                        if (accept)
                            counting++;
                    }
                }
            }
        }
        // cout << counting << endl;

        // col = row
        for (int col = 0; col < m; col++)
        {
            for (int len = 2; len <= n; len++)
            {

                for (int ch = 0; ch < n; ch++)
                {
                    int accept = 1;
                    if (ch + len <= n)
                    {
                        for (int roop = 0; roop < len; roop++)
                        {
                            if (board[ch + roop][col] != '1')
                            {
                                accept = 0;
                                break;
                            }
                        }
                        if (accept)
                            counting++;
                    }
                }
            }
        }
        // cout << counting << endl;
        for (int row = 1; row < n; row++)
        {
            for (int col = 1; col < m; col++)
            {
                // cout << "size " << row << " " << col << " " << endl;

                for (int i = 0; i < n && i + row < n; i++)
                {
                    for (int j = 0; j < m && j + col < m; j++)
                    {
                        int accept = 1;
                        // cout << i << " " << j << " >>" << endl;

                        for (int wi = i; wi <= i + row; wi++)
                        {
                            for (int wj = j; wj <= j + col; wj++)
                            {
                                if (board[wi][wj] != '1')
                                {
                                    accept = 0;
                                    break;
                                }
                                // cout << wi << wj << "    ";
                            }
                            if (accept == 0)
                                break;
                        }
                        if (accept)
                            counting++;

                        // cout << endl;
                    }
                    // cout << endl;
                }
            }
            // cout << endl;
        }

        ans.push_back(counting);
    }
    for (list<int>::iterator itr = ans.begin(); itr != ans.end(); itr++)
    {
        cout << *itr << endl;
    }
}