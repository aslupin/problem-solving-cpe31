#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <set>
using namespace std;
int main()
{
    int n, c, d;
    scanf("%d", &n);
    typedef pair<int, int> tuple;
    multiset<tuple> works;
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &c, &d);
        works.insert(make_pair(c, d));
    }
    int onGoing = 0, lateMax = 0, thisX = 0, thisD = 0;
    for (multiset<tuple>::iterator itr = works.begin(); itr != works.end(); itr++)
    {

        //( 10,  30)( 20,  20)( 50,  10)

        onGoing += itr->second;

        // printf("( %d,  %d)", itr->first, itr->second);

        if (lateMax < onGoing - itr->first)
        {
            lateMax = onGoing - itr->first;
            thisX = onGoing;
            thisD = itr->first;
        }
    }
    printf("%d", (((thisX - thisD - 10) * 1000) > 0) ? ((thisX - thisD - 10) * 1000) : 0);
}
