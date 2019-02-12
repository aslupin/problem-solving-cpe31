#include <iostream>
#include <queue>
using namespace std;

// int bfs(int)
// {
// }
int main()
{
    typedef pair<int, int> tuple;
    queue<tuple> Q;
    int col, row;
    char chr;
    cin >> row >> col;
    int box[row][col];
    bool visited[row][col];
    string ans = "no";
    for (int i = 0; i < row; i++)
    { // ADJ MATRIX
        for (int j = 0; j < col; j++)
        {
            cin >> chr;
            if (chr == '#')
                box[i][j] = 0;
            else if (chr == '.')
                box[i][j] = 1;

            visited[i][j] = 0;
        }
    }

    if (row >= 2)
        for (int c = 0; c < col; c++)
        { // LOOP FIND BOX
            if (ans == "yes")
                break;
            if (c != col - 1)
            { // NO BOX AT THE END.
                if (box[0][c] == 1 && box[0][c + 1] == 1 && box[1][c] == 1 && box[1][c + 1] == 1)
                { // FOUND BOX ON FIRST LINE.

                    Q.push(make_pair(0, c));
                    while (!Q.empty())
                    {
                        int start = Q.front().first;
                        int i = Q.front().second;
                        // cout << start << " , " << i << endl;
                        if (start == row - 2)
                        {
                            if (box[start + 1][i] == 1 && box[start + 1][i + 1] == 1)
                            {
                                // cout << start << " " << i << " " << c;
                                ans = "yes";
                                break;
                            }
                        }

                        Q.pop();

                        if (box[start + 2][i] == 1 && box[start + 2][i + 1] == 1)
                        { // DOWN
                            if (visited[start + 1][i] == 0)
                            {
                                visited[start + 1][i] = 1;
                                Q.push(make_pair(start + 1, i));
                            }
                        }
                        if (box[start - 1][i] == 1 && box[start - 1][i + 1] == 1)
                        { // UP
                            if (visited[start - 1][i] == 0)
                            {
                                visited[start - 1][i] = 1;
                                Q.push(make_pair(start - 1, i));
                            }
                        }
                        if (box[start][i - 1] == 1 && box[start + 1][i - 1] == 1)
                        { // LEFT
                            if (visited[start][i - 1] == 0)
                            {
                                visited[start][i - 1] = 1;
                                Q.push(make_pair(start, i - 1));
                            }
                        }
                        if (box[start][i + 2] == 1 && box[start + 1][i + 2] == 1)
                        { // RIGHT
                            if (visited[start][i + 1] == 0)
                            {
                                visited[start][i + 1] = 1;
                                Q.push(make_pair(start, i + 1));
                            }
                        }
                    }
                    if (ans == "yes")
                        break;
                }
            }
            if (ans == "yes")
                break;
        }
    cout << ans;
}