#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;


bool sortByfirstGreater(const pair<int,int> &a, const pair<int,int> &b){
    return (a.first > b.first); 
}

int main()
{
    char typePerson;
    int n, bound, g;
    scanf("%d", &n);

    typedef pair<int, int> tuple;
    typedef pair<tuple, int> marketStructure;
    vector<marketStructure> market; // ## ((bound, g), result)

    vector<int> seller, buyer;
    vector<int> typeSell, typeBuy;
    vector<tuple> queSeller, queBuyer;
    int nSeller=0, nBuyer=0;
    for (int m = 0; m < n; m++)
    {
        scanf(" %c %d %d", &typePerson, &bound, &g);
        market.push_back(make_pair(make_pair(bound, g), 0)); // push to m.
        if (typePerson == '1')
        { // BUYER
            nBuyer++;
            typeBuy.push_back(m);
            buyer.push_back(m);
            queBuyer.push_back(make_pair(market[m].first.first, m));
            sort(queBuyer.begin(), queBuyer.end(), sortByfirstGreater);
            // bool itMe = false;
            // int me = 0;
            // for (int i = 0; i < buyer.size(); i++)
            // {
                int i = buyer.size()-1;
                int eQueueIndex = buyer[i];
                if (market[eQueueIndex].first.second > 0)
                {
                    for (int s = 0; s < queSeller.size(); s++)
                    { // LOOP IN SELLER
                        if (market[queSeller[s].second].first.second <= 0 || market[eQueueIndex].first.second <= 0)
                            continue;
                        if (market[eQueueIndex].first.first >= market[queSeller[s].second].first.first)
                        {
                            if (market[eQueueIndex].first.second >= market[queSeller[s].second].first.second) // Gb >= Gs
                            {
                                market[eQueueIndex].first.second -= market[queSeller[s].second].first.second;
                                market[eQueueIndex].second += (market[eQueueIndex].first.first * market[queSeller[s].second].first.second);
                                market[queSeller[s].second].second += (market[eQueueIndex].first.first * market[queSeller[s].second].first.second);
                                market[queSeller[s].second].first.second = 0;
                                // queSeller.erase(queSeller.begin() + s);
                                // isBreak = true;
                                // break;
                            }
                            else // Gb < Gs
                            {
                                market[queSeller[s].second].first.second -= market[eQueueIndex].first.second;
                                market[eQueueIndex].second += (market[eQueueIndex].first.first * market[eQueueIndex].first.second);
                                market[queSeller[s].second].second += (market[eQueueIndex].first.first * market[eQueueIndex].first.second);
                                market[eQueueIndex].first.second = 0;
                                // buyer.erase(buyer.begin() + i);
                                // itMe = true;
                                // me = i;
                                // isBreak = true;
                                break;
                            }
                        }
                    }
                    // if(isBreak){
                    //     break;
                    // }
                }
            // }
            // if(itMe){
            //      buyer.erase(buyer.begin() + me);
            // }
       
        }

        else
        {
            nSeller++;
            typeSell.push_back(m);
            seller.push_back(m);
            queSeller.push_back(make_pair(market[m].first.first, m));
            sort(queSeller.begin(), queSeller.end());
            // bool itMe = false;
            // int me = 0;

            // for (int i = 0; i < seller.size(); i++){
                // bool isBreak = false;
                int i = seller.size()-1;
                int eQueueIndex = seller[i];
                if (market[eQueueIndex].first.second > 0)
                {
                    for (int b = 0; b < queBuyer.size(); b++)
                    { // LOOP IN BUYER

                        if (market[queBuyer[b].second].first.second <= 0 || market[eQueueIndex].first.second <= 0)
                            continue;
                        if (market[eQueueIndex].first.first <= market[queBuyer[b].second].first.first)
                        {
                            if (market[eQueueIndex].first.second >= market[queBuyer[b].second].first.second) // Gs >= Gb
                            {
                                market[eQueueIndex].first.second -= market[queBuyer[b].second].first.second;
                                market[eQueueIndex].second += (market[eQueueIndex].first.first * market[queBuyer[b].second].first.second);
                                market[queBuyer[b].second].second += (market[eQueueIndex].first.first * market[queBuyer[b].second].first.second);
                                market[queBuyer[b].second].first.second = 0;
                            }
                            else // Gs < Gb
                            {
                                market[queBuyer[b].second].first.second -= market[eQueueIndex].first.second;
                                market[eQueueIndex].second += (market[eQueueIndex].first.first * market[eQueueIndex].first.second);
                                market[queBuyer[b].second].second += (market[eQueueIndex].first.first * market[eQueueIndex].first.second);
                                market[eQueueIndex].first.second = 0;
                                // seller.erase(seller.begin() + i);
                                // isBreak = true;
                                // itMe = true;
                                // me = i;
                                break;
                            }
                        }
                    }
                    // if(isBreak){
                    //     break;
                    // }
                        
                }
            // }
            // if(itMe){
            //      seller.erase(seller.begin() + me);
            // }
    
        }
        //  cout << "########" << endl;
        // for (int i = 0; i < market.size(); i++)
        // {
        //     cout << i << " " << market[i].first.first << " " << market[i].first.second << " " << market[i].second << endl;
        // }

        
    }
    cout << endl << "buyer" << endl;                
    for(vector<tuple>::iterator it = queBuyer.begin(); it != queBuyer.end(); it++) 
    cout << "(" << it->first << "," << it->second << ") ";

    cout << endl << "seller" << endl;                
    for(vector<tuple>::iterator it = queSeller.begin(); it != queSeller.end(); it++)
    cout << "(" << it->first << "," << it->second << ") ";
    int sumSeller = 0, sumBuyer = 0;
    if(nSeller < nBuyer){
        for (int i = 0; i < typeSell.size(); i++)
                    sumSeller += market[typeSell[i]].second;
        printf("%d", sumSeller);    
    }
    else{
        for (int i = 0; i < typeBuy.size(); i++)
                    sumBuyer += market[typeBuy[i]].second;
        printf("%d", sumBuyer);    
    }
}