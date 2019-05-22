#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;
int main(){
    int n,q,l,ques;
    
    cin >> n >> q;
    int box[n];
    vector<int> uni[n], mycon;
    
    for(int i=0; i<n; i++){
        scanf("%d", &l);
        mycon.push_back(l);
        // if(i>1){
        //     mycon.push_back(box[i] + box[i-1]);
        //     mycon.push_back(box[i] + box[i-1] + box[i-2]);
        // }
    }

    // for(int i=0;i< 2;i++){
    //     for(int j=1;j<= n-i;j++){
            
    //         if(i == 0){
    //             scanf("%d", &l);
    //             uni[i].push_back(l);
    //             mycon.push_back(l);
    //         }
    //         else{
    //             if(j != 0){
    //             uni[i].push_back(uni[i-1][j] + uni[i-1][j-1]);
    //             mycon.push_back(uni[i-1][j] + uni[i-1][j-1]);
    //             }
    //         }
    //     }
    // }
//       for(int i=0;i< 2;i++){
//         for(int j=0;j< n-i;j++){
//             cout << uni[i][j]<< " ";
//         }cout << endl;}
// sort(mycon.begin(), mycon.end());
//     for(int i=0;i<mycon.size();i++){
//         cout << mycon[i] << " ";
//     }

    

    
    for(int i=0;i<q;i++){
        scanf("%d", &ques);
        if(binary_search(mycon.begin(), mycon.end(), ques)){
            printf("Y");
        }
        else printf("N");
    }
}