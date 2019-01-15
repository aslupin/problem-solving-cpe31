#include <iostream>
#include <stdlib.h>
using namespace std;

int dir[4] = {0, 0, 0, 0}; // N S E W
int x = 0, y = 0;
string walk;
int miss;

void getDis()
{
    for (int i = 0; i < walk.length(); i++)
    {
        if (walk[i] == 'N')
        {
            y++;
            dir[0]++;
        }
        if (walk[i] == 'S')
        {
            y--;
            dir[1]++;
        }
        if (walk[i] == 'E')
        {
            x++;
            dir[2]++;
        }
        if (walk[i] == 'W')
        {
            x--;
            dir[3]++;
        }
    }
}

int main()
{
    cin >> walk >> miss;
    getDis();             // get position
    if (x >= 0 && y >= 0) // 1
    {
        while (miss > 0)
        {
            if (dir[1] != 0) // S
                dir[1]--;
            else if (dir[3] != 0) // W
                dir[3]--;
            else
            {
                if (dir[0] != 0) // N
                    dir[0]--;
                else if (dir[2] != 0) // E
                    dir[2]--;
            }
            // dir[0]--; // N
            miss--;
        }
    }
    else if (x >= 0 && y < 0) // 4
    {
        while (miss > 0)
        {
            if (dir[0] != 0) // N
                dir[0]--;
            else if (dir[3] != 0) // W
                dir[3]--;
            else
            {
                if (dir[1] != 0) // S
                    dir[1]--;
                else if (dir[2] != 0) // E
                    dir[2]--;
            }

            miss--;

            // if (dir[1] != 0) // S
            //     dir[1]--;
            // else if (dir[2] != 0) // E
            //     dir[2]--;
            // else
            //     dir[0]--; // N
            // miss--;
        }
        // cout << dir[1] << endl;
    }
    else if (x < 0 && y >= 0) // 2
    {
        while (miss > 0)
        {
            if (dir[1] != 0) // S
                dir[1]--;
            else if (dir[2] != 0) // E
                dir[2]--;
            else
            {
                if (dir[0] != 0) // N
                    dir[0]--;
                else if (dir[3] != 0) // W
                    dir[3]--;
            }
            // dir[0]--; // N
            miss--;

            // if (dir[0] != 0) // N
            //     dir[0]--;
            // else if (dir[3] != 0) // W
            //     dir[3]--;
            // else
            //     dir[1]--; // S
            // miss--;
        }
        // cout << "4" << endl;
    }
    else if (x < 0 && y < 0) // 3
    {
        while (miss > 0)
        {
            if (dir[0] != 0) // N
                dir[0]--;
            else if (dir[2] != 0) // E
                dir[2]--;
            else
            {
                if (dir[1] != 0) // S
                    dir[1]--;
                else if (dir[3] != 0) // W
                    dir[3]--;
            }
            // dir[1]--; // S
            miss--;
        }
    }
    else // x == y
    {
        dir[0] += miss;
        miss = 0;
    }

    cout << (abs(dir[0] - dir[1]) + abs(dir[2] - dir[3])) * 2;
}
