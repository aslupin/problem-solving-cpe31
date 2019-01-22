#include <iostream>
#include <stack>
using namespace std;

int main()
{

    int n;
    cin >> n;
    stack<char> parent[n];
    string ans[n];
    string txt;
    for (int i = 0; i < n; i++)
    {
        cin >> txt;
        ans[i] = "yes";
        for (int j = 0; j < txt.length(); j++)
        {
            // cout << txt[j] << ' ';
            if (txt[j] == '{' || txt[j] == '(' || txt[j] == '[')
                parent[i].push(txt[j]);
            else
            {
                if (!parent[i].empty())
                {
                    if (txt[j] == '}' && parent[i].top() == '{')
                    {
                        parent[i].pop();
                    }
                    else if (txt[j] == ')' && parent[i].top() == '(')
                    {
                        parent[i].pop();
                    }
                    else if (txt[j] == ']' && parent[i].top() == '[')
                    {
                        parent[i].pop();
                    }
                    else
                    {
                        ans[i] = "no";
                        break;
                    }
                }
                else
                {
                    ans[i] = "no";
                    break;
                }
            }
        }
        // cout << parent[i].empty() << endl;
        if (!parent[i].empty())
            ans[i] = "no";
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << endl;
}
