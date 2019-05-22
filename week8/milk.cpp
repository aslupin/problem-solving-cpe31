#include <stdio.h>
#include <set>
using namespace std;

int main()
{
    int n, q;
    int x, y;
    char command;
    scanf("%d %d", &n, &q);
    int mycom[n];
    set<int> mymilk[n];

    for (int i = 0; i < n; i++)
    {
        mycom[i] = i;
        mymilk[i].insert(i);
    }

    for (int i = 0; i < q; i++)
    {
        scanf(" %c %d %d", &command, &x, &y);
        x--;
        y--;

        if (command == 'c')
        {
            if (mycom[x] != mycom[y])
            {
                
                
                if(mymilk[mycom[x]].size() > mymilk[mycom[y]].size()){
                    int temp = mycom[y];
                    y = mycom[y];
                    mymilk[mycom[x]].insert(mymilk[y].begin(), mymilk[y].end());
                    for (set<int>::iterator itr = mymilk[y].begin(); itr != mymilk[y].end(); itr++)
                            mycom[*itr] = mycom[x];
                    mymilk[temp].clear();
                }
                else{
                    
                    int temp = mycom[x];
                    x = mycom[x];
                    mymilk[mycom[y]].insert(mymilk[x].begin(), mymilk[x].end());
                    for (set<int>::iterator itr = mymilk[x].begin(); itr != mymilk[x].end(); itr++)
                            mycom[*itr] = mycom[y];
                    mymilk[temp].clear();
                }
                
            }
        }
        else
        {
            if (mycom[x] == mycom[y])
                printf("yes\n");
            else
                printf("no\n");
        }
        // printf("\n");
        // for(int i=0;i<n;i++) printf("%d ", mycom[i]);
        // printf("\n");
    }
}