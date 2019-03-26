#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main()
{
    int cc = 0;
    int n, m, ei, eii;

    cin >> n >> m;
    int a[10] vector<int> vertex[n];
    queue<int> q;

    bool visited[n];

    for (int i = 0; i < m; i++)
    {
        cin >> ei >> eii;
        ei--;
        eii--;
        vertex[ei].push_back(eii);
        vertex[eii].push_back(ei);
    }

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    // for (int i = 0; i < n; i++)
    // {
    //     if (visited[i] == 0)
    //     {
    //         q.push(i);
    //         cc++;
    //         while (!q.empty())
    //         {
    //             int front = q.front();
    //             visited[front] = 1;
    //             q.pop();
    //             for (int j = 0; j < vertex[front].size(); j++)
    //             {
    //                 if (visited[vertex[front][j]] == 0)
    //                 {
    //                     visited[vertex[front][j]] = 1;
    //                     q.push(vertex[front][j]);
    //                 }
    //             }
    //         }
    //     }
    // }
    // cout << cc;
}