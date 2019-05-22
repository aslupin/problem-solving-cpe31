#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;

typedef pair<int, int> mst;
typedef pair<mst, int> st;
// pair< pair<int,int>, int>
class CompareDist
{
public:
    bool operator()(st n1, st n2)
    {
        return n1.second > n2.second;
    }
};

int main()
{
    // เลือกโครงสร้าง
    int a, b, w;
    int n, m;
    cin >> n >> m;
    vector<mst> mymst[n];
    // ((1,2),3)
    priority_queue<st, vector<st>, CompareDist> Q;

    bool notVisited[n];
    int distance[n];

    // Initial graph
    for (int i = 0; i < n; i++)
    {
        notVisited[i] = true;
        distance[i] = 9999999;
        //  dist[i] = 9999999;
    }
    // build graph
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> w;
        a--; // index 0
        b--; // index 0
        // vertex a -> vertex b  >> weight
        mymst[a].push_back(make_pair(w, b));

        // vertex b -> vertex a  >> weight
        mymst[b].push_back(make_pair(w, a));
    }

    // Dijkstra
    // start S
    Q.push(make_pair(make_pair(0, 0), 0));
    distance[0] = 0;

    while (!Q.empty())
    {
        int ii = Q.top().first.second;
        Q.pop();
        if (notVisited[ii])
        {
            notVisited[ii] = false;
            for (int j = 0; j < mymst[ii].size(); j++)
            {
                if (notVisited[mymst[ii][j].second])
                {
                    if (distance[ii] + mymst[ii][j].first < distance[mymst[ii][j].second])
                        distance[mymst[ii][j].second] = distance[ii] + mymst[ii][j].first;
                    Q.push(make_pair(make_pair(mymst[ii][j].first, mymst[ii][j].second), distance[mymst[ii][j].second]));
                }
            }
        }
    }
    cout << distance[n - 1] << endl;
}