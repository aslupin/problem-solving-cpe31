#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n;
    while(1){
        cin >> n;
        if(n == 0) break;
        
        int outStation[n];
        while(1){
            bool isBreak = false;
            bool isCon = false;
            for(int i=0; i<n ;i++){
                cin >> outStation[i];
                if(outStation[i] == 0){
                    cout << endl;
                    isBreak = true;
                    break;
                }
                if(i != 0){
                    if(outStation[i] - outStation[i-1] < -2){
                        cout << "No" << endl;
                        isCon = true;
                    }
                }
            }
            if(isCon) continue;
            if(isBreak) break;
            cout << "Yes" << endl;;
        }
    }
}