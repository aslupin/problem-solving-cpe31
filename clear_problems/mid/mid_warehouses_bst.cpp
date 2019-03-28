#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int main()
{
    // bool gg[100000][100000];
    int n, m, k;
    int a, b;
    // cin >> n >> m >> k;
    scanf("%d %d %d", &n, &m, &k);
    vector<int> vertex[n];
    vector<int> gc_vertex;
    bool visited[n];

    for (unsigned i = 0; i < m; i++)
    {
        // cin >> a >> b;
        scanf("%d %d", &a, &b);
        a--;
        b--;

        for (int e = 0; e < vertex[a].size(); e++)
        {
            if (binary_search(vertex[vertex[a][e]].begin(), vertex[vertex[a][e]].end(), b) == false)
            {
                vertex[vertex[a][e]].push_back(b);
                sort(vertex[vertex[a][e]].begin(), vertex[vertex[a][e]].end());
            }
        }

        for (int e = 0; e < vertex[b].size(); e++)
        {
            if (binary_search(vertex[vertex[b][e]].begin(), vertex[vertex[b][e]].end(), a) == false)
            {
                vertex[vertex[b][e]].push_back(a);
                sort(vertex[vertex[b][e]].begin(), vertex[vertex[b][e]].end());
            }
        }

        vertex[a].push_back(b);
        vertex[b].push_back(a);
        sort(vertex[a].begin(), vertex[a].end());
        sort(vertex[b].begin(), vertex[b].end());
    }

    for (unsigned i = 0; i < k; i++)
    {
        // cin >> a >> b;
        scanf("%d %d", &a, &b);
        a--;
        b--;
        if (binary_search(vertex[a].begin(), vertex[a].end(), b))
            printf("1\n");
        else
            printf("0\n");
    }
}