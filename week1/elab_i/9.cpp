#include <iostream>
using namespace std;

int main()
{
    int n;
    int dis = 1000;
    int counting = 0;
    cin >> n;
    int truck[n][2];
    for (int i = 0; i < n; i++)
    {
        cin >> truck[i][0];
        truck[i][1] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        if (truck[i][1])
        {
            truck[i][1] = 0;
            dis -= truck[i][0];
            for (int j = 0; j < n; j++)
            {
                if (truck[j][0] <= dis && truck[j][1] == 1)
                {
                    truck[j][1] = 0;
                    dis -= truck[j][0];
                }
            }
            counting++;
            dis = 1000;
        }
    }
    cout << counting;
}