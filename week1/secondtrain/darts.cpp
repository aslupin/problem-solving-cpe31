#include <iostream>
#include <math.h>
using namespace std;

int getScore(int x, int y)
{
    double pos = sqrt(pow(x, 2) + pow(y, 2));

    if (pos <= 2)
        return 5;
    else if (pos <= 4)
        return 4;
    else if (pos <= 6)
        return 3;
    else if (pos <= 8)
        return 2;
    else if (pos <= 10)
        return 1;
    else
        return 0;
}
int main()
{
    int n_dok;
    cin >> n_dok;
    int x, y;
    int score = 0;
    for (int i = 0; i < n_dok; i++)
    {
        cin >> x >> y;
        score += getScore(x, y);
    }
    cout << score;
}