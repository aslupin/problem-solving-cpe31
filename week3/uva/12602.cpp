#include <iostream>
#include <list>
#include <cmath>
using namespace std;

int main()
{
    list<string> ans;
    int n;
    cin >> n;
    string plate[n];
    for (int i = 0; i < n; i++)
    {
        cin >> plate[i];

        int lice = 0;
        string save_number = "";
        int checker = 1;
        for (int j = 0; j < plate[i].length(); j++)
        {
            if (j == 0 || j == 1 || j == 2)
            {
                lice += ((int)plate[i][j] - 65) * pow(26, 2 - j);
            }
            else if (j == 3)
                continue;
            else
            {
                if (plate[i][j] == '0' && checker)
                {
                    continue;
                }
                else
                {
                    checker = 0;
                    save_number += plate[i][j];
                }
            }
        }
        if (abs(lice - stoi(save_number)) <= 100)
            ans.push_back("nice");
        else
            ans.push_back("not nice");
        // cout << save_number << endl;
    }
    for (list<string>::iterator itr = ans.begin(); itr != ans.end(); itr++)
    {
        cout << *itr << endl;
    }
}