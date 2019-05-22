#include <vector>
#include <stdio.h>
#include <set>
#include <iostream>
#include <algorithm>
using namespace std;

string process;
int nVertexMilk, nProcess, ioX, ioY;

int main()
{
    
    // INPUT 
    scanf("%d %d", &nVertexMilk, &nProcess);
    set<int> inSet[nVertexMilk];
    int superSet[nVertexMilk];
    // INITIAL
    for (int i = 0; i < nVertexMilk; i++)
    {
        inSet[i].insert(i);
        superSet[i] = i;
        
    }

    
    // PROCESS
    for (int i = 0; i < nProcess; i++)
    {
        scanf("%s %d %d", &process, &ioX, &ioY);
        int x = ioX - 1;
        int y = ioY - 1;

        if (process == "c")
        {
            if (superSet[ioX] != superSet[ioY])
            {
                
                
                if(inSet[superSet[x]].size() > inSet[superSet[y]].size()){
                    int temp = superSet[y];
                    y = superSet[y];
                    inSet[superSet[x]].insert(inSet[y].begin(), inSet[y].end());
                    for (auto itr = inSet[y].begin(); itr != inSet[y].end(); itr++)
                            superSet[*itr] = superSet[x];
                    inSet[temp].clear();
                }
                else{
                    
                    int temp = superSet[x];
                    x = superSet[x];
                    inSet[superSet[y]].insert(inSet[x].begin(), inSet[x].end());
                    for (auto itr = inSet[x].begin(); itr != inSet[x].end(); itr++)
                            superSet[*itr] = superSet[y];
                    inSet[temp].clear();
                }
                
            }
            else continue;
        }
        else if(process == "q")
        {
            if (superSet[ioX] != superSet[ioY])
                printf("no");
            else
                printf("yes");

            printf("\n");
        }
        
    }
}