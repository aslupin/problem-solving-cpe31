#include <iostream>
using namespace std;
int main()
{
    int score, sum = 0;
    int stage_inp, stage, n;
    cin >> stage >> n;
    int max_score[stage];

    for (int i = 0; i < stage; i++)
        max_score[i] = 99999;

    for (int i = 0; i < n; i++)
    {
        cin >> stage_inp >> score;
        stage_inp--;
        if (max_score[stage_inp] > score)
            max_score[stage_inp] = score;
    }
    for (int i = 0; i < stage; i++)
    {
        sum += max_score[i];
    }
    cout << sum << endl;
    for (int i = 0; i < stage; i++)
    {
        cout << i + 1 << " " << max_score[i] << endl;
    }
}