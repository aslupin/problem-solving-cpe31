#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> mst;
typedef pair<mst, int> st;

class CompareDist
{
public:
    bool operator()(st n1, st n2) {
        return n1.second > n2.second;
    }
};

int main(){
    
    
    int a,b,w;
    int n, m;
    cin >> n >> m;
    vector<mst> mymst[n];
    priority_queue<st, vector<st>, CompareDist> Q;
    set<int> q;
    bool notVisited[n];
    int distance[n];
    for(int i=0;i<n;i++){
         notVisited[i] = true;
         distance[i] = 9999999;
        
    }

    for(int i=0;i<m;i++){
        cin >> a >> b >> w;
        a--;
        b--;
        mymst[a].push_back(make_pair(w,b));
        mymst[b].push_back(make_pair(w,a));
    }



    Q.push(make_pair(make_pair(0,0),0)); // ((x,y) , z )
    distance[0] = 0;

    while(!Q.empty()){
        int ii = Q.top().first.second;
        Q.pop();

        if(notVisited[ii]){
            notVisited[ii] = false;
            for(int j=0; j<mymst[ii].size(); j++){
                if(notVisited[mymst[ii][j].second]){     

                if(distance[ii] + mymst[ii][j].first < distance[mymst[ii][j].second])
                        distance[mymst[ii][j].second] = distance[ii] + mymst[ii][j].first;

                // This code unused object first of first that can change container to set with pair or priority q of pair.
                Q.push(make_pair(make_pair(mymst[ii][j].first, mymst[ii][j].second),  distance[mymst[ii][j].second]));
                }
                    
            }
            
        }
        
    }

cout << distance[n-1] << endl;


}