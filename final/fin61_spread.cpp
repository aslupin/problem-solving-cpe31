
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> t;
typedef pair<t, t> mst;
class CompareDist
{
public:
    bool operator()(mst n1, mst n2)
    {
        return n1.first.first > n2.first.first;
    }
};

int main()
{

    int a, b, w;
    int n, m;
    int d;

    cin >> n >> m;
    int clocker[n];
    vector<t> mymst[n];
    priority_queue<mst, vector<mst>, CompareDist> Q;
    bool notVisited[n];
    for (int i = 0; i < n; i++)
    {
        cin >> clocker[i];
        notVisited[i] = true;
    }

    for (int k = 0; k < m; k++)
    {
        cin >> a >> b >> w;
        a--;
        b--;
        mymst[a].push_back(make_pair(w, b));
        mymst[b].push_back(make_pair(w, a));
        int i = a;
        int ii = b;
        int mm = 0;
        if ((w % (clocker[i] + clocker[ii])) != 0 && ((clocker[i] + clocker[ii]) < w))
            mm = 1;
        int d = (w / (clocker[i] + clocker[ii])) + mm;

        Q.push(make_pair(make_pair(d, w), make_pair(a, b)));
        Q.push(make_pair(make_pair(d, w), make_pair(b, a)));
    }

    
    int cc = 0;
    int ans = 0;
    while (!Q.empty())
    {
        int w = Q.top().first.second;
        int i = Q.top().second.first;
        int ii = Q.top().second.second;

        Q.pop();
        if (notVisited[ii] || notVisited[i])
        {
            cc++;
            int mm = 0;
            if ((w % (clocker[i] + clocker[ii])) != 0 && ((clocker[i] + clocker[ii]) < w))
                mm = 1;
            int d = (w / (clocker[i] + clocker[ii])) + mm;
            if (d >= cc || ans < d)
                ans = d;
            notVisited[ii] = false;
            notVisited[i] = false;
        }
    }
    cout << ans;
}