#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
int main()
{
    char builder;
    int w, h;
    int ans[2] = {0};
    int major_dir = 0;
    cin >> w >> h;
    int dolla_count = w * (h - 1), max_ans = 0;
    // TR - (STACK)
    typedef pair<int, int> tuple;     // x,y in stack
    typedef pair<int, tuple> walking; // (direction ,(x,y))

    // 0 => next floor
    // 1 => go left
    // 2 => go right

    // edge[m] - STRUCTURE
    typedef pair<bool, bool> bool_pair;
    typedef pair<bool_pair, bool_pair> result_xy; // ((checker , edge[m].left.result), (checker , edge[m].right.result))
    typedef pair<bool_pair, result_xy> result;    // ((checker,edge[m].nextfloor.result), ((checker , edge[m].left.result), (checker , edge[m].right.result)))
    // typedef pair<bool, result> checkerAndResult;  // (checker, result)
    typedef pair<int, result> edgeStructure;
    // (typeStanding , (edge[m].nextfloor.result, (edge[m].left.result , edge[m].right.result)))
    queue<tuple> new_way;
    // vector<int> ans(0);
    vector<edgeStructure> edge[2][h];
    stack<walking> deep;
    queue<walking> setter;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
        {
            // cin >> builder;
            scanf(" %c", &builder);

            new_way.push(make_pair(i, j));
            if (builder == '#') // -1
            {
                edge[0][i].push_back(make_pair(-1, make_pair(make_pair(0, 0), make_pair(make_pair(0, 0), make_pair(0, 0)))));
                edge[1][i].push_back(make_pair(-1, make_pair(make_pair(0, 0), make_pair(make_pair(0, 0), make_pair(0, 0)))));
            }

            else if (builder == '.') // 0
            {
                edge[0][i].push_back(make_pair(0, make_pair(make_pair(0, 0), make_pair(make_pair(0, 0), make_pair(0, 0)))));
                edge[1][i].push_back(make_pair(0, make_pair(make_pair(0, 0), make_pair(make_pair(0, 0), make_pair(0, 0)))));
            }
            else if (builder == '@') // 1
            {
                edge[0][i].push_back(make_pair(1, make_pair(make_pair(0, 0), make_pair(make_pair(0, 0), make_pair(0, 0)))));
                edge[1][i].push_back(make_pair(1, make_pair(make_pair(0, 0), make_pair(make_pair(0, 0), make_pair(0, 0)))));
            }
            else if (builder == '$') // 2
            {

                edge[0][i].push_back(make_pair(2, make_pair(make_pair(0, 0), make_pair(make_pair(0, 0), make_pair(0, 0)))));
                edge[1][i].push_back(make_pair(2, make_pair(make_pair(0, 0), make_pair(make_pair(0, 0), make_pair(0, 0)))));
                // dolla_count++;
                // if (i != 0)
                // {
                //     new_way.push(make_pair(i - 1, j));
                // }
            }
            // dolla_count++;

            // cout << i << " " << j << endl;
        }
    // dolla_count = 0;
    for (int pm = 0; pm < dolla_count + 1; pm++)
    {

        // initial
        int m = 0;
        if (pm != 0)
        {

            m = 1;
            ans[m] = 0;
            for (int ii = 0; ii < h; ii++)
                for (int jj = 0; jj < w; jj++)
                {
                    edge[1][ii][jj].first = edge[0][ii][jj].first;
                    edge[1][ii][jj].second.first.first = 0;
                    edge[1][ii][jj].second.first.second = 0;
                    edge[1][ii][jj].second.second.first.first = 0;
                    edge[1][ii][jj].second.second.first.second = 0;
                    edge[1][ii][jj].second.second.second.first = 0;
                    edge[1][ii][jj].second.second.second.second = 0;
                }
            edge[1][new_way.front().first][new_way.front().second].first = 0;
            edge[1][new_way.front().first][new_way.front().second].second.first.first = 0;
            edge[1][new_way.front().first][new_way.front().second].second.first.second = 0;
            edge[1][new_way.front().first][new_way.front().second].second.second.first.first = 0;
            edge[1][new_way.front().first][new_way.front().second].second.second.first.second = 0;
            edge[1][new_way.front().first][new_way.front().second].second.second.second.first = 0;
            edge[1][new_way.front().first][new_way.front().second].second.second.second.second = 0;

            // cout << endl
            //      << endl
            //      << new_way.front().first << " " << new_way.front().second << endl;

            new_way.pop();

            // cout << endl;
            // cout << endl;
            // for (int ii = 0; ii < h; ii++)
            // {
            //     for (int jj = 0; jj < w; jj++)
            //     {
            //         cout << edge[1][ii][jj].first << " ";
            //     }
            //     cout << endl;
            // }

            while (!deep.empty())
                deep.pop();
            while (!setter.empty())
                setter.pop();
        }

        for (int i = 0; i < w; i++)
            for (int f = 1; f <= 2; f++)
            {
                major_dir = f;
                if (edge[m][0][i].first == 0)
                {
                    deep.push(make_pair(f, make_pair(0, i)));
                    setter.push(make_pair(f, make_pair(0, i)));
                }
                else if (f == 1)
                {
                    deep.push(make_pair(1, make_pair(0, i)));
                    setter.push(make_pair(1, make_pair(0, i)));
                }

                else if (f == 2)
                {
                    deep.push(make_pair(2, make_pair(0, i)));
                    setter.push(make_pair(2, make_pair(0, i)));
                }
                // cout << "Start !!" << endl;
                while (!deep.empty())
                {
                    int dir = deep.top().first;
                    int x = deep.top().second.first;
                    int y = deep.top().second.second;

                    if (major_dir != dir && dir != 0) // WHEN YOU GO NEXT FLOOR YOU CANT DOUBLE NEXT IT
                        major_dir = dir;

                    // cout << dir << "  (" << x << ", " << y << ")" << endl;
                    // cout << "result " << edge[m][x][y].second.second.first.second << " " << edge[m][x][y].second.second.second.second << endl;
                    deep.pop();

                    if ((edge[m][x][y].second.first.first == 1 && dir == 0) ||
                        (edge[m][x][y].second.second.first.first == 1 && dir == 1) ||
                        (edge[m][x][y].second.second.second.first == 1 && dir == 2))
                    {

                        while (!setter.empty())
                        {
                            // edge[m][i][j](make_pair(2, make_pair(make_pair(0,0),make_pair(make_pair(0,0),make_pair(0,0)))));
                            int setResult = 1;
                            if (dir == 1)
                                setResult = edge[m][x][y].second.second.first.second;
                            else if (dir == 2)
                                setResult = edge[m][x][y].second.second.second.second;
                            else if (dir == 0)
                            {
                                if (major_dir == 0)
                                    setResult = edge[m][x][y].second.second.first.second;
                                else if (major_dir == 1)
                                    setResult = edge[m][x][y].second.second.second.second;
                            }

                            if (setter.front().first == 0 && edge[m][setter.front().second.first][setter.front().second.second].second.first.first == 0)
                            {                                                                                                       // NEXT FLOOR
                                edge[m][setter.front().second.first][setter.front().second.second].second.first.second = setResult; // result
                                edge[m][setter.front().second.first][setter.front().second.second].second.first.first = 1;          // checker
                            }
                            else if (setter.front().first == 1 && edge[m][setter.front().second.first][setter.front().second.second].second.second.first.first == 0)
                            {                                                                                                              // LEFT
                                edge[m][setter.front().second.first][setter.front().second.second].second.second.first.second = setResult; // result
                                edge[m][setter.front().second.first][setter.front().second.second].second.second.first.first = 1;          // checker
                            }
                            else if (setter.front().first == 2 && edge[m][setter.front().second.first][setter.front().second.second].second.second.second.first == 0)
                            {                                                                                                               // RIGHT
                                edge[m][setter.front().second.first][setter.front().second.second].second.second.second.second = setResult; // result
                                edge[m][setter.front().second.first][setter.front().second.second].second.second.second.first = 1;          // checker
                            }

                            setter.pop();
                        }
                        // while (!deep.empty())
                        //     deep.pop();
                    }
                    else
                    { // never come here
                        if (edge[m][x][y].first == -1)
                        { // DOUBLY-NODE
                            if (dir == 1)
                            { // LEFT
                                // cout << " L " << endl;
                                if (y == 0) // cycle at left
                                {
                                    deep.push(make_pair(2, make_pair(x, y))); // ROTATE DIR TO RIGHT
                                    setter.push(make_pair(2, make_pair(x, y)));
                                }

                                else
                                {
                                    deep.push(make_pair(1, make_pair(x, y - 1))); // GO LEFT
                                    setter.push(make_pair(1, make_pair(x, y - 1)));
                                }
                            }

                            else if (dir == 2)
                            { // RIGHT
                                // cout << " R " << endl;
                                if (y == w - 1) // cycle at right
                                {
                                    deep.push(make_pair(1, make_pair(x, y))); // ROTATE DIR TO LEFT
                                    setter.push(make_pair(1, make_pair(x, y)));
                                }

                                else
                                {
                                    deep.push(make_pair(2, make_pair(x, y + 1))); // GO RIGHT
                                    setter.push(make_pair(2, make_pair(x, y + 1)));
                                }
                            }
                        }
                        else if (edge[m][x][y].first == 0)
                        { // NEXT FLOOR - NODE
                            // cout << " next " << endl;
                            deep.push(make_pair(major_dir, make_pair(x + 1, y)));
                            setter.push(make_pair(major_dir, make_pair(x + 1, y)));
                        }

                        else if (edge[m][x][y].first == 1)
                        { // @ NODE
                            // cout << " @ " << endl;
                            while (!setter.empty())
                            {
                                // edge[m][i][j](make_pair(2, make_pair(make_pair(0,0),make_pair(make_pair(0,0),make_pair(0,0)))));
                                if (setter.front().first == 0)
                                { // NEXT FLOOR
                                    if (major_dir == 1)
                                    {
                                        edge[m][setter.front().second.first][setter.front().second.second].second.second.first.second = 0; // result
                                        edge[m][setter.front().second.first][setter.front().second.second].second.second.first.first = 1;  // checker
                                    }
                                    else if (major_dir == 2)
                                    {
                                        edge[m][setter.front().second.first][setter.front().second.second].second.second.second.second = 0; // result
                                        edge[m][setter.front().second.first][setter.front().second.second].second.second.second.first = 1;  // checker
                                    }
                                    // edge[m][setter.front().second.first][setter.front().second.second].second.first.second = 0; // result
                                    // edge[m][setter.front().second.first][setter.front().second.second].second.first.first = 1;  // checker
                                }
                                else if (setter.front().first == 1)
                                {                                                                                                      // LEFT
                                    edge[m][setter.front().second.first][setter.front().second.second].second.second.first.second = 0; // result
                                    edge[m][setter.front().second.first][setter.front().second.second].second.second.first.first = 1;  // checker
                                }
                                else
                                {                                                                                                       // RIGHT
                                    edge[m][setter.front().second.first][setter.front().second.second].second.second.second.second = 0; // result
                                    edge[m][setter.front().second.first][setter.front().second.second].second.second.second.first = 1;  // checker
                                }

                                setter.pop();
                            }
                        }
                        else
                        { // $ NODE
                            // cout << " $ " << endl;
                            while (!setter.empty())
                            {
                                if (setter.front().first == 0)
                                { // NEXT FLOOR
                                    if (major_dir == 1)
                                    {
                                        edge[m][setter.front().second.first][setter.front().second.second].second.second.first.second = 1; // result
                                        edge[m][setter.front().second.first][setter.front().second.second].second.second.first.first = 1;  // checker
                                    }
                                    else if (major_dir == 2)
                                    {
                                        edge[m][setter.front().second.first][setter.front().second.second].second.second.second.second = 1; // result
                                        edge[m][setter.front().second.first][setter.front().second.second].second.second.second.first = 1;  // checker
                                    }
                                    // edge[m][setter.front().second.first][setter.front().second.second].second.first.second = 1; // result
                                    // edge[m][setter.front().second.first][setter.front().second.second].second.first.first = 1;  // checker
                                }
                                else if (setter.front().first == 1)
                                {                                                                                                      // LEFT
                                    edge[m][setter.front().second.first][setter.front().second.second].second.second.first.second = 1; // result
                                    edge[m][setter.front().second.first][setter.front().second.second].second.second.first.first = 1;  // checker
                                }
                                else
                                {                                                                                                       // RIGHT
                                    edge[m][setter.front().second.first][setter.front().second.second].second.second.second.second = 1; // result
                                    edge[m][setter.front().second.first][setter.front().second.second].second.second.second.first = 1;  // checker
                                }

                                setter.pop();
                            }
                        }
                    }
                }
            }
        // cout << endl;

        // for (int iii = 0; iii < h; iii++)
        // {
        //     for (int jjj = 0; jjj < w; jjj++)
        //     {
        //         cout << edge[m][iii][jjj].second.second.first.second << edge[m][iii][jjj].second.second.second.second << " ";
        //     }
        //     cout << endl;
        // }
        for (int a = 0; a < w; a++)
        {

            ans[m] += edge[m][0][a].second.second.first.second + edge[m][0][a].second.second.second.second;
            // cout << edge[m][0][a].second.second.first.second << " " << edge[m][0][a].second.second.second.second << " , ";
        }
        // cout << ans[m] << endl;
        if (m == 0)
            max_ans = ans[m];
        else
        {
            if (ans[m] > max_ans)
                max_ans = ans[m];
        }
        // cout << ans[m] << endl;
        // cout << endl;
    }
    cout << ans[0] << " " << max_ans;
}
