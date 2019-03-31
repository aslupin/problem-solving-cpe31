#include <iostream>
#include <queue>
using namespace std;
int main(){
    int n, power;
    typedef pair<int, int> xy;
    // typedef pair<xy, int> structure;
    queue<xy> q;
    cin >> n >> power;
    int gameMap[n][n];
    bool visited[n][n];
    
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            cin >> gameMap[i][j];
            visited[i][j] = true;
        }
            
    visited[0][0] = false;
    q.push(make_pair(0,0));
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        int hight = gameMap[x][y];
        // int currPower = q.front().second;
        q.pop();

        if( x == n-1 && y == n-1){cout << "yes"; return 0;}
        if(y <= n-2 && gameMap[x][y+1] - hight <= power){
            if(visited[x][y+1]){
                q.push(make_pair(x, y+1));
                visited[x][y+1] = false;
            }
        }
        if(y >= 1 && gameMap[x][y-1] - hight <= power){
            if(visited[x][y-1]){
                q.push(make_pair(x, y-1));
                visited[x][y-1] = false;
            }
        }
        if(x>= 1 && gameMap[x-1][y] - hight <= power){
            if(visited[x-1][y]){
                q.push(make_pair(x-1, y));
                visited[x-1][y] = false;
            }
        }
        if(x <= n-2 && gameMap[x+1][y] - hight <= power){
            if(visited[x+1][y]){
                q.push(make_pair(x+1, y));
                visited[x+1][y] = false;
            }
        }
    }
    cout << "no";

}