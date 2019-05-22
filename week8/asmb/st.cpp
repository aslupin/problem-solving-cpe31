#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> newStructure; 

class compare
{
public:
    bool operator()(newStructure n1, newStructure n2) {
        return n1.first > n2.first;
    }
};


int main(){    
    int n,edge;
    cin >> n >> edge;
    vector<newStructure> adjList[n];
    priority_queue <newStructure, vector<newStructure>, compare> queue;
    bool visited[n];
    int dist[n];
    for(int i=0; i<edge; i++) {
        int a,b,w;
        cin >> a >> b >> w;
        a--;
        b--;
        adjList[a].push_back(make_pair(w,b));
        adjList[b].push_back(make_pair(w,a));
    }
    for(int i=0; i<n; i++) {
        visited[i] = false;
        dist[i] = 1000000;
    }
    dist[0] = 0;
    queue.push(make_pair(0,0));
    while(!queue.empty()) {
        int front = queue.top().second;
        queue.pop();
        if(!visited[front]) {
            visited[front] = true;
            for(int i=0; i<adjList[front].size(); i++) {
                if(!visited[adjList[front][i].second]) {
                    int edgeDistance = dist[front] + adjList[front][i].first;
                    if(edgeDistance < dist[adjList[front][i].second]) {
                        dist[adjList[front][i].second] = edgeDistance;
                    }
                    queue.push(make_pair(dist[adjList[front][i].second], adjList[front][i].second));
                }
            }
        }
    }
    cout << dist[n-1] << endl;
}