#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;
typedef pair<int, int> mst;
typedef pair<mst, int> st;
    

class CompareDist
{
public:
    bool operator()(st n1, st n2) {
        return n1.second < n2.second;
    }
};

int main(){
    
    
    int a,b,w;
    int n, m;
    cin >> n >> m;
    vector<mst> mymst[n];
    // set<int> s;
    priority_queue<st, vector<st>, CompareDist> Q;
    set<int> q;
    bool notVisited[n];
    int distance[n];
    // int dist[n];
    for(int i=0;i<n;i++){
         notVisited[i] = true;
         distance[i] = 9999999;
        //  dist[i] = 9999999;
    }

    for(int i=0;i<m;i++){
        cin >> a >> b >> w;
        a--;
        b--;
        mymst[a].push_back(make_pair(w,b));
        mymst[b].push_back(make_pair(w,a));
    }

    // dist[0] = 0;
    
    
    
    Q.push(make_pair(make_pair(0,0),0));
    q.insert(0);
    // notVisited[0] = false;
    distance[0] = 0;

    while(!Q.empty()){

        // int i = Q.top().first.first;
        int ii = Q.top().first.second;
        // int walk = Q.top().second;
        
        Q.pop();
        // cout << walk << " _ ";

        // int ii = * q.begin();
        // q.erase(q.begin());

        if(notVisited[ii]){
            notVisited[ii] = false;
            for(int j=0; j<mymst[ii].size(); j++){
                if(notVisited[mymst[ii][j].second]){     
                    
                if(distance[ii] + mymst[ii][j].first < distance[mymst[ii][j].second])
                        distance[mymst[ii][j].second] = distance[ii] + mymst[ii][j].first;

                
                    Q.push(make_pair(make_pair(mymst[ii][j].first, mymst[ii][j].second), distance[ii]));
                    // q.insert(mymst[ii][j].second);
                }
                    
            }
            
        }
        
    }

//     for(int i=0;i<n;i++)
// cout << distance[i] << " ";
cout << distance[n-1] << endl;


}