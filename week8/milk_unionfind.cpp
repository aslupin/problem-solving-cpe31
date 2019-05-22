#include <stdio.h>
#include <vector>
// #include <queue>
using namespace std;

int main()
{
    int n, q;
    int x, y;
    char command;
    // queue<int> Q;
    scanf("%d %d", &n, &q);
    int super[n];
    vector<int> mm[n];

    for (int i = 0; i < n; i++)
    {
        super[i] = i;
        mm[i].push_back(i);
    }

    for (int i = 0; i < q; i++)
    {
        scanf(" %c %d %d", &command, &x, &y);
        x--;
        y--;

        if (command == 'c')
        {
            if (super[x] != super[y])
            {
                
                mm[super[x]].insert(mm[super[x]].end() ,mm[super[y]].begin(), mm[super[y]].end());
                for(int e=0; e<mm[super[y]].size(); e++)
                    super[mm[super[y]][e]] = super[x];
                
                
            }
        }
        else
        {
            if (super[x] == super[y])
                printf("yes\n");
            else
                printf("no\n");
        }
        // printf("\n");
        // for(int i=0;i<n;i++) printf("%d ", super[i]);
        // printf("\n");
    }
}