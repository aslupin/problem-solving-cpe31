#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int main()
{
    int n, m, k;
    int a, b;
    // cin >> n >> m >> k;
    scanf("%d %d %d", &n, &m, &k);
    vector<int> vertex[n];
    vector<int> gc_vertex;
    bool visited[n];
    int node_type[n];
    for (unsigned i = 0; i < m; i++)
    {
        // cin >> a >> b;
        scanf("%d %d", &a, &b);
        a--;
        b--;
        // if (binary_search(vertex[a].begin(), vertex[a].end(), b) == false)
        vertex[a].push_back(b);
        // if (binary_search(vertex[b].begin(), vertex[b].end(), a) == false)
        vertex[b].push_back(a);
        // sort(vertex[a].begin(), vertex[a].end());
        // sort(vertex[b].begin(), vertex[b].end());
    }
    for (unsigned i = 0; i < n; i++)
    {
        visited[i] = true;
        node_type[i] = 0;
    }

    queue<int> q;
    int type = -1;
    for (int i = 0; i < n; i++)
    {
        if (visited[i])
        {
            type++;
            q.push(i);
            visited[i] = false;
            node_type[i] = type;
            while (!q.empty())
            {
                int front = q.front();
                q.pop();
                for (int e = 0; e < vertex[front].size(); e++)
                {
                    if (visited[vertex[front][e]])
                    {
                        visited[vertex[front][e]] = false;
                        q.push(vertex[front][e]);
                        node_type[vertex[front][e]] = type;
                    }
                }
            }
        }
    }

    for (unsigned i = 0; i < k; i++)
    {
        // cin >> a >> b;
        scanf("%d %d", &a, &b);
        if (node_type[--a] == node_type[--b])
            printf("1\n");
        else
            printf("0\n");
    }
}