#include <iostream>
using namespace std;
int main()
{
    int ans = 0;
    int pos = 0;
    string s, p;
    cin >> s >> p;
    for (int i = 0; i < p.length(); i++)
    {

        if (p[i] == s[pos])
            pos++;
        if (pos == s.length())
        {
            ans++;
            pos = 0;
        }
    }
    cout << ans;
}