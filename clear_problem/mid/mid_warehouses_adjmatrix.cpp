#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
bool vertex[100000][100000] = {{0}};
int main()
{
    int n, m, k;
    int a, b;
    // cin >> n >> m >> k;
    scanf("%d %d %d", &n, &m, &k);
    // vector<int> vertex[n];
    // vector<int> gc_vertex;
    // bool visited[n];
    // bool vertex[n][n];

    for (unsigned i = 0; i < m; i++)
    {
        // cin >> a >> b;
        scanf("%d %d", &a, &b);
        a--;
        b--;
        vertex[a][b] = true;
        vertex[b][a] = true;
    }

    for (unsigned i = 0; i < k; i++)
    {
        // cin >> a >> b;
        scanf("%d %d", &a, &b);
        a--;
        b--;
        if (vertex[a][b] == true)
            printf("1\n");
        else
            printf("0\n");
    }
}