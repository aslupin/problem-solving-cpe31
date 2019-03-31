#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n, a, b, r, x, y;
    cin >> n >> a >> b >> r;
    r *= r;
    int missing = 0;
    for(int i=0; i<n; i++){
        cin >> x >> y;
        if(pow(x-a, 2)+pow(y-b, 2) <= r) missing++;
    }
    cout << missing;
}