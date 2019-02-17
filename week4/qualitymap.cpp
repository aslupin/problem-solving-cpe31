#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int n, m, land_counting = 0;
    char sign;
    typedef pair<int, int> tuple;
    queue<tuple> q;
    cin >> n >> m;
    int mapq[n][m];
    bool visited[n][m];
    int landing[2] = {0};
    bool checker[2] = {0}; // * $

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> sign;
            if (sign == '.')
                mapq[i][j] = 1;
            else if (sign == '*')
                mapq[i][j] = 2;
            else if (sign == '$')
                mapq[i][j] = 3;

            if (sign == '#')
            {
                mapq[i][j] = 0;
                visited[i][j] = 0;
            }
            else
            {
                visited[i][j] = 1;
            }
        }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (visited[i][j])
            {
                land_counting = 0;
                checker[0] = 0;
                checker[1] = 0;
                q.push(make_pair(i, j));
                visited[i][j] = 0;
                // cout << "NEW LAND " << i << " " << j << endl;

                while (!q.empty())
                {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    land_counting++;

                    if (mapq[x][y] == 2)
                        checker[0] = 1;
                    else if (mapq[x][y] == 3)
                        checker[1] = 1;

                    if (x != n - 1) //DOWN
                        if (mapq[x + 1][y] != 0 && visited[x + 1][y])
                        {
                            visited[x + 1][y] = 0;
                            q.push(make_pair(x + 1, y));
                        }
                    if (x != 0) // UP
                        if (mapq[x - 1][y] != 0 && visited[x - 1][y])
                        {
                            visited[x - 1][y] = 0;
                            q.push(make_pair(x - 1, y));
                        }
                    if (y != 0) // LEFT
                        if (mapq[x][y - 1] != 0 && visited[x][y - 1])
                        {
                            visited[x][y - 1] = 0;
                            q.push(make_pair(x, y - 1));
                        }
                    if (y != m - 1) // RIGHT
                        if (mapq[x][y + 1] != 0 && visited[x][y + 1])
                        {
                            visited[x][y + 1] = 0;
                            q.push(make_pair(x, y + 1));
                        }
                }

                if (checker[0] && checker[1])
                    landing[0] += land_counting;
                else if (checker[0] || checker[1])
                    landing[1] += land_counting;
            }
        }
    cout << landing[0] << " " << landing[1];
}