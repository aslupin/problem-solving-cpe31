#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class CompareDist
{
public:
    bool operator()(pair<int,int> n1,pair<int,int> n2) {
        return n1.first > n2.first;
    }
};

int main(){
    typedef pair<int, int> mst;
    
    
    int a,b,w;
    int n, m;
    cin >> n >> m;
    vector<mst> mymst[n];
    priority_queue<mst, vector<mst>, CompareDist> Q;
    bool notVisited[n];
    for(int i=0;i<n;i++) notVisited[i] = true;

    for(int i=0;i<m;i++){
        cin >> a >> b >> w;
        a--;
        b--;
        mymst[a].push_back(make_pair(w,b));
        mymst[b].push_back(make_pair(w,a));
    }
    
    Q.push(make_pair(0,0));

    int ans = 0;
    while(!Q.empty()){

        int i = Q.top().first;
        int ii = Q.top().second;
        Q.pop();
        if(notVisited[ii]){
            ans += i;
            notVisited[ii] = false;
            
            for(int j=0; j<mymst[ii].size(); j++){
                    Q.push(make_pair(mymst[ii][j].first, mymst[ii][j].second));
                    
            }
        }
        
    
    }
cout << ans;



}