#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n, jump;
    int x, y, cmin = -1;
    cin >> n >> jump;
    n += 2;
    jump *= jump;
    typedef pair<int, int> tuple;
    vector<tuple> edge;
    vector<int> adj[n];
    // queue<int> q;
    queue<tuple> q;

    edge.push_back(make_pair(0, 0));
    for (int i = 1; i <= n - 2; i++)
    {
        cin >> x >> y;
        edge.push_back(make_pair(x, y));
    }
    edge.push_back(make_pair(100, 100));

    for (int i = 0; i < n; i++)
    { // BUILD  ADJ- MATRIX
        for (int j = 0; j < n; j++)
        {
            int termX = pow(edge[j].first - edge[i].first, 2);
            int termY = pow(edge[i].second - edge[j].second, 2);
            adj[i].push_back(termX + termY);
        }
    }
    bool init = 1;
    bool visited[n];
    for (int b = 0; b < n; b++)
        visited[b] = 1;

    q.push(make_pair(0, 0));
    while (!q.empty())
    {
        int tv = q.front().first;
        int c = q.front().second;
        q.pop();
        visited[tv] = 0;
        if (tv == adj[0].size() - 1)
        { // AT (100, 100)
            if (init)
            {
                cmin = c;
                init = 0;
            }
            else if (c < cmin)
                cmin = c;
            break;
        }

        for (int go = 0; go < adj[tv].size(); go++)
        {
            if (adj[tv][go] <= jump && adj[tv][go] != 0)
            {
                if (visited[go])
                {
                    visited[go] = 0;
                    q.push(make_pair(go, c + 1));
                }
            }
        }
    }

    cout << cmin << endl;
}