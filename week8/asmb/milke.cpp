#include <vector>
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

char process;
int nVertexMilk, nProcess, ioX, ioY;

int main()
{
    
    // INPUT 
    scanf("%d %d", &nVertexMilk, &nProcess);
    vector<int> inSet[nVertexMilk];
    int superSet[nVertexMilk];
    // INITIAL
    for (int i = 0; i < nVertexMilk; i++)
    {
        inSet[i].push_back(i);
        superSet[i] = i;
        
    }

    
    // PROCESS
    for (int i = 0; i < nProcess; i++)
    {
        scanf(" %c %d %d", &process, &ioX, &ioY);
        int x = ioX - 1;
        int y = ioY - 1;

        if(process == 'q')
        {
                    if (superSet[x] != superSet[y])
                        printf("no");
                    else
                        printf("yes");

                    printf("\n");
        }
        else if (process == 'c')
        {
            if (superSet[x] != superSet[y])
            {
                
                int temp;
                if(inSet[superSet[x]].size() < inSet[superSet[y]].size()){
                    temp = superSet[x];
                    x = superSet[x];
                    inSet[superSet[y]].insert(inSet[superSet[y]].end(),inSet[x].begin(), inSet[x].end());
                    for (auto itr = inSet[x].begin(); itr != inSet[x].end(); itr++)
                            superSet[*itr] = superSet[y];
                    
                }
                else{
                    temp = superSet[y];
                    // int t = x;
                    // x = y;
                    // y = t;
                    y = superSet[y];
                    inSet[superSet[x]].insert(inSet[superSet[x]].end(), inSet[superSet[y]].begin(), inSet[superSet[y]].end());
                    for (auto itr = inSet[y].begin(); itr != inSet[y].end(); itr++)
                            superSet[*itr] = superSet[x];   
                }
                inSet[temp].clear();
                
            }
            else continue;
        }
        
        
    }
}