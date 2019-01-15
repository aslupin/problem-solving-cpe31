#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
    int N, L;

    int dis = 0;
    cin >> N >> L;
    int box[N];
    for (int i = 0; i < N; i++)
    {
        cin >> box[i];
    }

    for (int i = 0; i < N; i++)
    {
        if (i < N - 1)
        {
            for (int j = i + 1; j < N; j++)
            {
                if (abs(box[i] - box[j]) <= L)
                {
                    dis++;
                }
            }
        }
    }
    cout << dis;
}