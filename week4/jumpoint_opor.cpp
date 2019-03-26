#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <math.h>

using namespace std;
int use[1005];
int BFS(vector<int> adj[], int n)
{
    int cur, depth = 1, found = 0;
    queue<int> q;
    use[0] = 1;
    while (!adj[0].empty())
    {
        q.push(adj[0].back());
        adj[0].pop_back();
        use[q.front()] = 1;
    }
    q.push(-1);
    while (!q.empty())
    {
        if (q.front() == -1)
        {
            if (q.size() == 1)
                break;
            depth++;
            q.push(-1);
            q.pop();
            continue;
        }
        else if (q.front() == n)
        {
            found = 1;
            break;
        }
        cur = q.front();
        while (!adj[cur].empty())
        {
            if (!use[adj[cur].back()])
            {
                q.push(adj[cur].back());
                use[q.front()] = 1;
            }
            adj[cur].pop_back();
        }
        q.pop();
    }
    if (!found)
        depth = -1;
    return depth;
}

int main()
{
    int n, r, x, y;
    typedef pair<int, int> tuple;
    vector<tuple> inp;
    vector<int> node[1005];
    cin >> n >> r;
    r *= r;
    inp.push_back(make_pair(0, 0));
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y;
        inp.push_back(make_pair(x, y));
    }
    inp.push_back(make_pair(100, 100));
    int i = 0, j = 0;
    for (vector<tuple>::iterator it = inp.begin(); it != inp.end(); it++)
    {
        j = i + 1;
        for (vector<tuple>::iterator jt = it + 1; jt != inp.end(); jt++)
        {
            if (pow(inp[i].first - inp[j].first, 2) + pow(inp[i].second - inp[j].second, 2) <= r)
            {
                node[i].push_back(j);
                node[j].push_back(i);
            }
            j++;
        }
        i++;
    }
    int ans;
    ans = BFS(node, n + 1);
    cout << ans;
}
