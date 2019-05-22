#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> st;

class compare
{
public:
    bool operator()(st n1, st n2)
    {
        return n1.first > n2.first;
    }
};

int main()
{
    int n, edge;
    cin >> n >> edge;
    vector<st> adjList[n];
    priority_queue<st, vector<st>, compare> queue;
    bool visited[n];
    int dist[n];

    for (int i = 0; i < edge; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;
        adjList[a].push_back(make_pair(w, b));
        adjList[b].push_back(make_pair(w, a));
    }

    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
        dist[i] = 1000000;
    }

    // Dijkstra
    dist[0] = 0;                 // (s) <- 0
    queue.push(make_pair(0, 0)); // q.push(vertex 0)
    // weight , vertex
    while (!queue.empty()) // queue หยุดเมื่อ empty
    {

        // cout << queue.top().first << " " << queue.top().second << endl;
        int front = queue.top().second; // ขอตัวเเรกของ q มาอยู่ในมือเรา
        queue.pop();                    // kill ทิ้ง

        if (!visited[front]) // ดักจุดที่เคยมาเเล้ว
        {
            visited[front] = true; // คุณมาเเล้วนะ!

            for (int i = 0; i < adjList[front].size(); i++)
            // จะดูว่ามี adjacent อะไรบ้างที่ติดกับ front ของเรา (adjList[adj ของจุดที่เราต้องการ])
            {
                if (!visited[adjList[front][i].second])
                // 0 | (10,2) , (20,3)
                // 1 | (30,5) , (26,4)
                // ณ adj นั้นๆ เราเคยมาป๊าว? (adjList[front][i].second = 2)
                {
                    int edgeDistance = dist[front] + adjList[front][i].first; // shortest path ณ จุดเราอยู่ + weight เส้นทางที่จะไป adj นั้น
                    if (edgeDistance < dist[adjList[front][i].second])
                    { // ถ้า ผลรวมของ shortest path ณ จุดเราอยู่ + weight เส้นทางที่จะไป adj น้อยกว่า (<) shortest path ของ adj นั้นๆ
                        dist[adjList[front][i].second] = edgeDistance;
                    }
                    // รัน BFS ต่อ โดยใส่ weight shortest path ของ adj นั้นๆ เเละ vertex adj นั้นๆลง Q (ต้องเรียงจากน้อยไปมากตาม weight เพราะว่าเราต้องเลือกเดินโดยเลือกเส้นทางที่สั้น)
                    queue.push(make_pair(dist[adjList[front][i].second], adjList[front][i].second));
                }
            }
        }
    }
    cout << dist[n - 1] << endl;
}