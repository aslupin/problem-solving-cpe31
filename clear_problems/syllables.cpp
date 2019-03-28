#include <iostream>
using namespace std;
int main()
{
    int n;
    string txt;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> txt;
        int count = 0, isNext = -2;
        for (int j = 0; j < txt.length(); j++)
        {
            if (txt[j] == 'a' || txt[j] == 'e' || txt[j] == 'i' || txt[j] == 'o' || txt[j] == 'u')
            {
                if (j != isNext + 1)
                {
                    count++;
                }
                isNext = j;
            }
        }
        cout << count << endl;
    }
}