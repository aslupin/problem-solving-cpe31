#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n, q;
    int x, y;
    char command;
    queue<int> Q;
    scanf("%d %d", &n, &q);
    int super[n];
    vector<int> mm[n];
    bool visited[n];

    for (int i = 0; i < n; i++)
    {
        super[i] = i;
        // mm[i].push_back(i);
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
                for(int t=0;t<n;t++) visited[t] = true;

                mm[x].push_back(y);
                mm[y].push_back(x);
                Q.push(y);
                visited[y] = false;
                while(!Q.empty()){
                    int front = Q.front();
                    Q.pop();
                    super[front] = super[x];

                    for(int adj=0;adj<mm[front].size();adj++){
                        if(visited[mm[front][adj]]){
                            visited[mm[front][adj]] =  false;
                            Q.push(mm[front][adj]);
                        }
                    }
                }
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