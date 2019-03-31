#include <iostream>
#include <queue>
using namespace std;
int main(){
    int n;
    int ePower;
    cin >> n;
    typedef pair<int, int> iPower;
    priority_queue<iPower> memRound[4];
    for(int i=1; i<=n*4; i++){
        cin >> ePower;
        if(i >=1 && i <= n) memRound[0].push(make_pair(ePower, i));
        else if(i >= n+1 && i <= 2*n)   memRound[1].push(make_pair(ePower, i));
        else if(i >= ((2*n)+1) && i<= 3*n)   memRound[2].push(make_pair(ePower, i));
        else if(i >= ((3*n)+1) && i<= 4*n)    memRound[3].push(make_pair(ePower, i));
    }
    int minA, maxA, minB, maxB, maxWin, minWin;
    
    if(memRound[0].top().first < memRound[1].top().first){
        minA = 0;
        maxA = 1;
    }
    else {
        minA = 1;
        maxA = 0;
    }
    if(memRound[2].top().first < memRound[3].top().first){
        minB = 2;
        maxB = 3;
    }
    else {
        minB = 3;
        maxB = 2;
    }
     if(memRound[maxA].top().first >memRound[maxB].top().first){maxWin = maxA; minWin = maxB;}
     else {maxWin = maxB; minWin = maxA;}
     
    cout << memRound[maxWin].top().second << " " << memRound[minWin].top().second << " " << memRound[minA].top().second << " " << memRound[minB].top().second;

    
    
}