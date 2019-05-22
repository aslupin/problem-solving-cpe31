#include <set>
#include <stdio.h>

using namespace std;

struct cc
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b) const
    {
        return (a.second < b.second);
    }
};

int main()
{
    int n;
    typedef pair<int, int> tuple;
    multiset<tuple, cc> mytuple;
    int i, ii;
    scanf("%d", &n);

    for (int j = 0; j < n; j++)
    {
        scanf("%d %d", &i, &ii);
        mytuple.insert(make_pair(i, ii));
    }

    int s = -1, t = -1, range = 0;
    // for (multiset<tuple, cc>::iterator itr = mytuple.begin(); itr != mytuple.end(); itr++)
    for (auto itr = mytuple.begin(); itr != mytuple.end(); itr++)
    {
        if (itr->first >= t)
        {
            s = itr->first;
            t = itr->second;
            range++;
        }
    }
    printf("%d", range);
}
