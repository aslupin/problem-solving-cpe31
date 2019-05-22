#include <iostream>
#include <stdio.h>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

struct classcomp {
  bool operator() (const pair<int,int> &a, const pair<int,int> &b) const
  {return (a.first > b.first);}
};

int main()
{
    int sum = 0;
    char typePerson;
    int n, bound, g;
    scanf("%d", &n);

    typedef pair<int, int> tuple;
    typedef pair<tuple, int> marketStructure;

    vector<marketStructure> market; // ## ((bound, g), result)
    multiset<tuple> queSeller;
    multiset<tuple, classcomp> queBuyer;

    for (int m = 0; m < n; m++)
    {
        scanf(" %c %d %d", &typePerson, &bound, &g);
        market.push_back(make_pair(make_pair(bound, g), 0)); // push to m.
        if (typePerson == '1')
        { // BUYER
            queBuyer.insert(make_pair(market[m].first.first, m));        
            multiset<tuple>::iterator it = queSeller.begin();
            while(it != queSeller.end())
            { // LOOP IN SELLER
            
                if (market[m].first.first >= market[it->second].first.first)
                {
                    if (market[m].first.second > market[it->second].first.second) // Gb >= Gs
                    {
                        market[m].first.second -= market[it->second].first.second;
                        market[m].second += (market[m].first.first * market[it->second].first.second);
                        market[it->second].second += (market[m].first.first * market[it->second].first.second);
                        sum += (market[m].first.first * market[it->second].first.second);
                        market[it->second].first.second = 0;
                        it = queSeller.erase(it);
                    }
                    else if (market[m].first.second == market[it->second].first.second) // Gb >= Gs
                    {
                        market[m].first.second -= market[it->second].first.second;
                        market[m].second += (market[m].first.first * market[it->second].first.second);
                        market[it->second].second += (market[m].first.first * market[it->second].first.second);
                        sum += (market[m].first.first * market[it->second].first.second);
                        market[it->second].first.second = 0;
                        market[m].first.second = 0;
                        break;
                    }
                    else // Gb < Gs
                    {
                        market[it->second].first.second -= market[m].first.second;
                        market[m].second += (market[m].first.first * market[m].first.second);
                        market[it->second].second += (market[m].first.first * market[m].first.second);
                        sum += (market[m].first.first * market[m].first.second);
                        market[m].first.second = 0;
                        break;
                    }
                }
                else break;
                
            }
        }

        else
        {
            queSeller.insert(make_pair(market[m].first.first, m));
            multiset<tuple, classcomp>::iterator it = queBuyer.begin();
            while(it != queBuyer.end())
            { // LOOP IN BUYER
                if (market[m].first.first <= market[it->second].first.first)
                {
                    if (market[m].first.second > market[it->second].first.second) // Gs >= Gb
                    {
                        market[m].first.second -= market[it->second].first.second;
                        market[m].second += (market[m].first.first * market[it->second].first.second);
                        market[it->second].second += (market[m].first.first * market[it->second].first.second);
                        sum += (market[m].first.first * market[it->second].first.second);
                        market[it->second].first.second = 0;
                        it = queBuyer.erase(it);
                    }
                    else if (market[m].first.second == market[it->second].first.second) // Gb >= Gs
                    {
                        market[m].first.second -= market[it->second].first.second;
                        market[m].second += (market[m].first.first * market[it->second].first.second);
                        market[it->second].second += (market[m].first.first * market[it->second].first.second);
                        sum += (market[m].first.first * market[it->second].first.second);
                        market[it->second].first.second = 0;
                        market[m].first.second = 0;
                        break;
                    }
                    else // Gs < Gb
                    {
                        market[it->second].first.second -= market[m].first.second;
                        market[m].second += (market[m].first.first * market[m].first.second);
                        market[it->second].second += (market[m].first.first * market[m].first.second);
                        sum += (market[m].first.first * market[m].first.second);
                        market[m].first.second = 0;
                        break;
                    }
                }
                else break;  
            }   
        }   
        printf("%d ", sum);    
    }
       printf("\nans : %d", sum);    
}
