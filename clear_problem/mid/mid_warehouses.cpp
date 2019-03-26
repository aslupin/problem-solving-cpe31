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
        visited[i] = true;

    for (unsigned i = 0; i < k; i++)
    {
        // cin >> a >> b;
        scanf("%d %d", &a, &b);
        a--;
        b--;
        // INITIAL
        bool have = false;
        while (!gc_vertex.empty())
        {
            int clear = gc_vertex.back();
            gc_vertex.pop_back();
            visited[clear] = true;
        }
        queue<int> q_head, q_tail;
        // FIRST PUSH
        q_head.push(a);
        q_tail.push(b);
        visited[a] = false;
        visited[b] = false;
        gc_vertex.push_back(a);
        gc_vertex.push_back(b);
        while (!q_head.empty() && !q_tail.empty())
        {
            if (!q_head.empty())
            {
                int front_head = q_head.front();
                visited[front_head] = false;
                gc_vertex.push_back(front_head);
                q_head.pop();
                if (front_head == b)
                {
                    have = true;
                    break;
                }
                for (int i = 0; i < vertex[front_head].size(); i++)
                {
                    if (vertex[front_head][i] == b)
                    {
                        have = true;
                        break;
                    }
                    if (visited[vertex[front_head][i]])
                    {
                        q_head.push(vertex[front_head][i]);
                        visited[front_head] = false;
                    }
                }
                if (have)
                    break;
            }

            if (!q_tail.empty())
            {
                int front_tail = q_tail.front();
                visited[front_tail] = false;
                gc_vertex.push_back(front_tail);
                q_tail.pop();
                if (front_tail == a)
                {
                    have = true;
                    break;
                }

                for (int i = 0; i < vertex[front_tail].size(); i++)
                {
                    if (vertex[front_tail][i] == a)
                    {
                        have = true;
                        break;
                    }
                    if (visited[vertex[front_tail][i]])
                    {
                        q_tail.push(vertex[front_tail][i]);
                        visited[front_tail] = false;
                    }
                }
                if (have)
                    break;
            }
        }
        printf("%d\n", have);
    }
}