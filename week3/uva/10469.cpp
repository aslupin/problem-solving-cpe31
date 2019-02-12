#define BITSIZE 32
#include <iostream>
#include <bitset>
#include <list>
#include <string>
using namespace std;

string getSum(string bi, string bii)
{
    int i, ii;
    int carry = 0, sum = 0;
    string sum_s = "";
    string ans = "";
    for (int j = 31; j >= 0; j--)
    {

        if (bi[j] == '0')
            i = 0;
        else
            i = 1;
        if (bii[j] == '0')
            ii = 0;
        else
            ii = 1;

        if (i + ii == 2)
        {
            sum = 0;
        }
        else if (i + ii == 0)
        {
            sum = 0;
        }
        else
        {
            sum = 1;
        }
        if (sum == 1)
            sum_s = "1";
        else
            sum_s = "0";

        // cout << i << " " << ii << " " << sum_s << "  " << bi[j] << " " << bii[j] << endl;
        ans = sum_s + ans;
    }
    return ans;
}

int main()
{
    list<unsigned long> ans;
    int ni, nii;
    while (cin >> ni >> nii)
    {
        string bi = bitset<BITSIZE>(ni).to_string();
        string bii = bitset<BITSIZE>(nii).to_string();
        // cout << bi << " " << bii << endl;
        // cout << bitset<BITSIZE>(getSum(bi, bii)).to_ulong() << endl;
        ans.push_back(bitset<BITSIZE>(getSum(bi, bii)).to_ulong());
    }
    for (list<unsigned long>::iterator it = ans.begin(); it != ans.end(); it++)
    {
        cout << *it << endl;
    }
}