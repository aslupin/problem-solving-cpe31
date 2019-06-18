#include <iostream>
using namespace std;

int main()
{
    char cm;
    int n;
    cin >> n;
    int box[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> cm;
            if (cm == '.')
            {
                box[i][j] = 1;
            }
            else if (cm == '\\')
            {
                box[i][j] = 2;
            }
            else if (cm == '/')
            {
                box[i][j] = 3;
            }
        }

    // left

    for (int i = 0; i < n; i++)
    {
        int wr = i, wc = 0;
        int state = 1;
        while (wr >= 0 && wr < n && wc < n && wc >= 0)
        {
            if (box[wr][wc] == 1)
            {
                if (state == 1)
                    wc++;
                else if (state == 2)
                    wc--;
                else if (state == 3)
                    wr--;
                else if (state == 4)
                    wr++;
            }
            else if (box[wr][wc] == 2)
            {
                if (state == 1)
                {
                    wr++;
                    state = 4;
                }
                else if (state == 2)
                {
                    wr--;
                    state = 3;
                }
                else if (state == 3)
                {
                    wc--;
                    state = 2;
                }
                else if (state == 4)
                {
                    wc++;
                    state = 1;
                }
            }
            else if (box[wr][wc] == 3)
            {
                if (state == 1)
                {
                    wr--;
                    state = 3;
                }
                else if (state == 2)
                {
                    wr++;
                    state = 4;
                }
                else if (state == 3)
                {
                    wc++;
                    state = 1;
                }
                else if (state == 4)
                {
                    wc--;
                    state = 2;
                }
            }
        }

        int ans;
        if (state == 1)
        { //r
            wc--;
            ans = (3 * n) - 1 - wr + 1;
        }
        else if (state == 2)
        { // l
            ans = wr + 1;
            wc++;
        }

        else if (state == 3)
        { // top
            wr++;
            ans = (4 * n) - 1 - wc + 1;
        }

        else if (state == 4)
        {
            wr--;
            ans = n + wc + 1;
        }

        // cout << wr << " " << wc << " | ";
        cout << ans << endl;
    }
    // bot
    for (int i = 0; i < n; i++)
    {
        int wr = n - 1, wc = i;
        int state = 3;
        while (wr >= 0 && wr < n && wc < n && wc >= 0)
        {
            if (box[wr][wc] == 1)
            {
                if (state == 1)
                    wc++;
                else if (state == 2)
                    wc--;
                else if (state == 3)
                    wr--;
                else if (state == 4)
                    wr++;
            }
            else if (box[wr][wc] == 2)
            {
                if (state == 1)
                {
                    wr++;
                    state = 4;
                }
                else if (state == 2)
                {
                    wr--;
                    state = 3;
                }
                else if (state == 3)
                {
                    wc--;
                    state = 2;
                }
                else if (state == 4)
                {
                    wc++;
                    state = 1;
                }
            }
            else if (box[wr][wc] == 3)
            {
                if (state == 1)
                {
                    wr--;
                    state = 3;
                }
                else if (state == 2)
                {
                    wr++;
                    state = 4;
                }
                else if (state == 3)
                {
                    wc++;
                    state = 1;
                }
                else if (state == 4)
                {
                    wc--;
                    state = 2;
                }
            }
        }

        int ans;
        if (state == 1)
        { //r
            wc--;
            ans = (3 * n) - 1 - wr + 1;
        }
        else if (state == 2)
        { // l
            ans = wr + 1;
            wc++;
        }

        else if (state == 3)
        { // top
            wr--;
            ans = (4 * n) - 1 - wc + 1;
        }

        else if (state == 4)
        {
            wr++;
            ans = n + wc + 1;
        }

        // cout << wr << " " << wc << " | ";
        cout << ans << endl;
    }
    // right
    for (int i = n - 1; i >= 0; i--)
    {
        int wr = i, wc = n - 1;
        int state = 2;
        while (wr >= 0 && wr < n && wc < n && wc >= 0)
        {
            if (box[wr][wc] == 1)
            {
                if (state == 1)
                    wc++;
                else if (state == 2)
                    wc--;
                else if (state == 3)
                    wr--;
                else if (state == 4)
                    wr++;
            }
            else if (box[wr][wc] == 2)
            {
                if (state == 1)
                {
                    wr++;
                    state = 4;
                }
                else if (state == 2)
                {
                    wr--;
                    state = 3;
                }
                else if (state == 3)
                {
                    wc--;
                    state = 2;
                }
                else if (state == 4)
                {
                    wc++;
                    state = 1;
                }
            }
            else if (box[wr][wc] == 3)
            {
                if (state == 1)
                {
                    wr--;
                    state = 3;
                }
                else if (state == 2)
                {
                    wr++;
                    state = 4;
                }
                else if (state == 3)
                {
                    wc++;
                    state = 1;
                }
                else if (state == 4)
                {
                    wc--;
                    state = 2;
                }
            }
        }

        int ans;
        if (state == 1)
        { //r
            wc--;
            ans = (3 * n) - 1 - wr + 1;
        }
        else if (state == 2)
        { // l
            ans = wr + 1;
            wc++;
        }

        else if (state == 3)
        { // top
            wr++;
            ans = (4 * n) - 1 - wc + 1;
        }

        else if (state == 4)
        {
            wr--;
            ans = n + wc + 1;
        }

        // cout << wr << " " << wc << " | ";
        cout << ans << endl;
    }
    // top
    for (int i = n - 1; i >= 0; i--)
    {
        int wr = 0, wc = i;
        int state = 4;
        while (wr >= 0 && wr < n && wc < n && wc >= 0)
        {
            if (box[wr][wc] == 1)
            {
                if (state == 1)
                    wc++;
                else if (state == 2)
                    wc--;
                else if (state == 3)
                    wr--;
                else if (state == 4)
                    wr++;
            }
            else if (box[wr][wc] == 2)
            {
                if (state == 1)
                {
                    wr++;
                    state = 4;
                }
                else if (state == 2)
                {
                    wr--;
                    state = 3;
                }
                else if (state == 3)
                {
                    wc--;
                    state = 2;
                }
                else if (state == 4)
                {
                    wc++;
                    state = 1;
                }
            }
            else if (box[wr][wc] == 3)
            {
                if (state == 1)
                {
                    wr--;
                    state = 3;
                }
                else if (state == 2)
                {
                    wr++;
                    state = 4;
                }
                else if (state == 3)
                {
                    wc++;
                    state = 1;
                }
                else if (state == 4)
                {
                    wc--;
                    state = 2;
                }
            }
        }

        int ans;
        if (state == 1)
        { //r
            wc--;
            ans = (3 * n) - 1 - wr + 1;
        }
        else if (state == 2)
        { // l
            ans = wr + 1;
            wc++;
        }

        else if (state == 3)
        { // top
            wr++;
            ans = (4 * n) - 1 - wc + 1;
        }

        else if (state == 4)
        {
            wr--;
            ans = n + wc + 1;
        }
        // cout << wr << " " << wc << " | ";
        cout << ans << endl;
    }
}