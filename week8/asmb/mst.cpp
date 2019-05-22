

#include <iostream>
#include <queue>
#include <vector>
#include <stdio.h>
using namespace std;

typedef pair<int, int> structure_prim;

class compare
{
public:
    bool operator()(structure_prim mem_i, structure_prim mem_ii) {
        return mem_ii.first < mem_i.first;
    }
};

int main(){
    
    int a,b,w,n,m;
    scanf("%d %d", &n, &m);
    vector<structure_prim> mystructure_prim[n];
    // vector<structure_prim, pair<int,int> > mystructure_prim[n];
    priority_queue<structure_prim, vector<structure_prim>, compare> myQ;
    bool gone[n];
    int sum = 0;

    for(int c=0;c<n;c++){
        gone[c] = 1;
    }

    for(int i=0;i<m;i++){
        scanf("%d %d %d", &a, &b, &w);
        mystructure_prim[b - 1].push_back(make_pair(w,a - 1));
        mystructure_prim[a - 1].push_back(make_pair(w,b - 1));
    }



    myQ.push(make_pair(0,0));
    while(!myQ.empty()){
        int len = myQ.top().first;
        int vertex = myQ.top().second;
        myQ.pop();

        if(gone[vertex] == 1){
            sum = sum + len;        
            gone[vertex] = 0;
            // EVERY NODE
            for(int eachVertexSide=0; eachVertexSide<mystructure_prim[vertex].size(); eachVertexSide++)
                    myQ.push(make_pair(mystructure_prim[vertex][eachVertexSide].first, mystructure_prim[vertex][eachVertexSide].second));
        }
        
        
    
    }
printf("%d", sum);
}