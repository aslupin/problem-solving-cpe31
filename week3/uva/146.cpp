#include <iostream>
#include <algorithm>
#include <list>
using namespace std;
int main()
{
    list<string> ans;
    string code;
    do
    {
        cin >> code;
        if (code == "#")
            break;

        if (next_permutation(code.begin(), code.end()))
            ans.push_back(code);
        else
            ans.push_back("No Successor");

    } while (1);

    for (list<string>::iterator itr = ans.begin(); itr != ans.end(); itr++)
    {
        cout << *itr << endl;
    }
}