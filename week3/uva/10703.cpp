#include <iostream>
#include <list>
using namespace std;
int main()
{
    list<string> ans;
    int w, h, n;
    while (1)
    {
        cin >> w >> h >> n;
        if (w == 0 && h == 0 && n == 0)
            break;
        int board[h][w];
        int subpos[n][4];
        int emptysub = 0;
        // INPUT
        int xi, xii, yi, yii;
        for (int i = 0; i < n; i++)
        {
            cin >> xi >> yi >> xii >> yii;
            subpos[i][0] = min(xi, xii) - 1;
            subpos[i][1] = min(yi, yii) - 1;
            subpos[i][2] = max(xi, xii) - 1;
            subpos[i][3] = max(yi, yii) - 1;
            // cout << subpos[i][0] << subpos[i][1] << " " << subpos[i][2] << subpos[i][3] << endl;
        }

        for (int i = 0; i < w; i++)
            for (int j = 0; j < h; j++)
            {
                int checker = 1;
                for (int pos = 0; pos < n; pos++)
                {
                    // cout << i << " " << j << endl;
                    if (i >= subpos[pos][0] && i <= subpos[pos][2] && j >= subpos[pos][1] && j <= subpos[pos][3])
                    {
                        checker = 0;
                    }
                }
                if (checker)
                    emptysub++;
            }
        cin.ignore();
        if (emptysub == 0)
        {
            ans.push_back("There is no empty spots.");
        }
        else if (emptysub == 1)
        {
            ans.push_back("There is one empty spot.");
        }
        else
        {
            ans.push_back("There are " + to_string(emptysub) + " empty spots.");
        }
    }
    // cout << emptysub;
    for (list<string>::iterator itr = ans.begin(); itr != ans.end(); itr++)
    {
        cout << *itr << endl;
    }
}