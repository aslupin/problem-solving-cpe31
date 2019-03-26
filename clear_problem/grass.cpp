#include <iostream>
using namespace std;

int main()
{
    char inp, command;
    int n, m, k;
    cin >> n >> m;
    int grass[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> inp;
            if (inp == 'x')
                grass[i][j] = 1;
            else if (inp == '.')
                grass[i][j] = 2;
            else if (inp == '#')
                grass[i][j] = 3;
        }

    for (int i = 0; i < m; i++)
    {
        cin >> command >> k;
        k = k - 1;
        if (command == 'L')
        {
            for (int eat = 0; eat < n; eat++)
            {
                if (grass[k][eat] == 2 || grass[k][eat] == 3)
                    break;
                grass[k][eat] = 2;
            }
        }
        if (command == 'R')
        {
            for (int eat = n - 1; eat >= 0; eat--)
            {
                if (grass[k][eat] == 2 || grass[k][eat] == 3)
                    break;
                grass[k][eat] = 2;
            }
        }

        if (command == 'U')
        {
            for (int eat = 0; eat < n; eat++)
            {
                if (grass[eat][k] == 2 || grass[eat][k] == 3)
                    break;
                grass[eat][k] = 2;
            }
        }
        if (command == 'D')
        {
            for (int eat = n - 1; eat >= 0; eat--)
            {
                if (grass[eat][k] == 2 || grass[eat][k] == 3)
                    break;
                grass[eat][k] = 2;
            }
        }
        if (command == 'A')
        {
            for (int eat = 0; eat < n; eat++)
            {
                if (grass[k][eat] == 2)
                {
                    grass[k][eat] = 1;
                }
            }
        }
        if (command == 'B')
        {
            for (int eat = 0; eat < n; eat++)
            {
                if (grass[eat][k] == 2)
                {
                    grass[eat][k] = 1;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grass[i][j] == 1)
                cout << 'x';
            else if (grass[i][j] == 2)
                cout << '.';
            else if (grass[i][j] == 3)
                cout << '#';
        }
        cout << endl;
    }
}