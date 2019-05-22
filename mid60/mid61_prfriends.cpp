#include <iostream>
#include <math.h>
// #include <stdio.h>
#include <vector>
using namespace std;

bool checkP(int x){
    for(int i=2; i<=sqrt(x);i++)
        if(x % i == 0) return 0;
    return 1;
}
int main(){
    vector<int> myp;
    int ans = 0;
    int L, R, c = -1;
    cin >> L >> R;
    for(int i=L ;i<=R;i++){
        if(checkP(i)){
            myp.push_back(i);
            c++;
            if(c != 0){
                // cout << "(" << myp[c] << "," << myp[c-1] << ")" << endl;
                if(myp[c] - myp[c-1] == 2) 
                    ans++;
            }
        }
    }
    // for(int i=0;i<myp.size();i++) cout << myp[i] << " ";
    // cout << ans;
    printf("%d", ans);
}