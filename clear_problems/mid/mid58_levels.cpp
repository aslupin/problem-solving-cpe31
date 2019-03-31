#include <iostream>
#include <queue>
using namespace std;
int main(){
    int n, m;
    int a, b, c;
    typedef pair<int, int> ab;
    typedef pair<ab, int> abc;
    queue<abc> stage;

    cin >> n >> m;

    for(int i=1; i<=n-1; i++){
        cin >> a >> b >> c; // CONDITIONS
        stage.push(make_pair(make_pair(a, b), c));
    }
    int maxA = -1, maxB = -1, maxC = -1;
    int level = 1;

    for(int play=1; play<=m; play++){
        cin >> a >> b >> c; // PLAY

        maxA = max(maxA, a);
        maxB = max(maxB, b);
        maxC = max(maxC, c);

        if(!stage.empty()){
            if(maxA >= stage.front().first.first && maxB >= stage.front().first.second && maxC >= stage.front().second){
                maxA = -1;
                maxB = -1;
                maxC = -1;
                stage.pop();
                level++;
            }
        }
    }
    cout << level;
}