#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
using namespace std;
int main(){
    int r,c;
    int a,b,wx,wy;
    typedef pair<int ,int> xy;
    typedef pair<xy, int> xyw;
    queue<xyw> q;
    queue<xy> spot;
    scanf("%d %d", &r, &c);
    char dig[r][c];
    bool visited[r][c];
    scanf("%d %d %d %d", &a, &b, &wx, &wy);
    a--; b--;
    spot.push(make_pair(a,b));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            scanf(" %c", &dig[i][j]);
            visited[i][j] = true;
            if(dig[i][j] == '*'){
                spot.push(make_pair(i,j));
            }
        }
    }
    // int x, wy;
    int bx , by;
    wx--; wy--;
    int minWalk = 9999999, thisWalk = 0;
    bool found = false;
    while(!spot.empty()){
        int si = spot.front().first;
        int sj = spot.front().second;
        spot.pop();
        char temps = dig[si][sj];
        dig[si][sj] = '.';
        for(int ccc=0; ccc<2; ccc++){
            bool rl = false, ud = false;
            bool r= false, l = false, u = false, d= false;
            
            if(ccc == 0) rl = true;
            else ud = true;

        thisWalk = 0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                visited[i][j] = true;
            }}

            q.push(make_pair(make_pair(a, b), thisWalk));
            visited[a][b] = false;
            while(!q.empty()){
                int x = q.front().first.first;
                int y = q.front().first.second;
                thisWalk = q.front().second;
                q.pop();
                // cout << x << " " << y << endl;
                if(x == wx && y == wy){
                    minWalk = min(minWalk, thisWalk);
                    // cout << "d";
                    found = true;
                    
                }
                if(x == si && y == sj){
                    if(rl && (r || l)){
                        if(r)
                            if(dig[x][y + 1] != '#' && dig[x][y + 1] != '*'  ){
                                if(visited[x][y+1]){
                                    visited[x][y+1] = false;
                                    q.push(make_pair(make_pair(x, y+1), thisWalk+1));
                                    r = false;
                                }
                            }
                        if(l)
                            if(dig[x][y - 1] != '#' && dig[x][y - 1] != '*' ){
                                if(visited[x][y-1]){
                                    visited[x][y-1] = false;
                                    q.push(make_pair(make_pair(x, y-1), thisWalk+1));
                                    l = false;
                                }
                            }
                    }
                    else if(ud && ( u || d)){
                        if(d)
                            if(dig[x-1][y] != '#' && dig[x-1][y] != '*' ){
                                if(visited[x-1][y]){
                                    visited[x-1][y] = false;
                                    q.push(make_pair(make_pair(x-1, y), thisWalk+1));
                                    d = false;
                                }
                            }
                        if(u)
                            if(dig[x+1][y] != '#' && dig[x+1][y] != '*' ){
                                if(visited[x+1][y]){
                                    visited[x+1][y] = false;
                                    q.push(make_pair(make_pair(x+1, y), thisWalk+1));
                                    u = false;
                                }
                            }
                    }
                }
                else{

                if(dig[x][y + 1] != '#' && dig[x][y + 1] != '*'  ){
                    if(visited[x][y+1]){
                        visited[x][y+1] = false;
                        if(x == si && y+1 == sj) r = true;
                        else r = false;
                        q.push(make_pair(make_pair(x, y+1), thisWalk+1));
                    }
                }
                if(dig[x][y - 1] != '#' && dig[x][y - 1] != '*' ){
                    if(visited[x][y-1]){
                        visited[x][y-1] = false;
                        if(x == si && y-1 == sj) l = true;
                        else l = false;
                        q.push(make_pair(make_pair(x, y-1), thisWalk+1));
                    }
                }
                if(dig[x-1][y] != '#' && dig[x-1][y] != '*' ){
                    if(visited[x-1][y]){
                        visited[x-1][y] = false;
                        if(x-1 == si && y == sj) d = true;
                        else d = false;
                        q.push(make_pair(make_pair(x-1, y), thisWalk+1));
                    }
                }
                if(dig[x+1][y] != '#' && dig[x+1][y] != '*' ){
                    if(visited[x+1][y]){
                        visited[x+1][y] = false;
                        if(x+1 == si && y == sj) u = true;
                        else u = false;
                        q.push(make_pair(make_pair(x+1, y), thisWalk+1));
                    }
                }

                }
                
            }



        }

       
        



        dig[si][sj] = temps;
    }


    if(minWalk == 9999999 || found == false) minWalk = -1;
    printf("%d", minWalk);
}