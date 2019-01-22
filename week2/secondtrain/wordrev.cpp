#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<char> stack_save_txt;
    string txt;
    string new_txt = "";
    cin >> txt;
    for (int i = 0; i < txt.length(); i++)
    {

        if (txt[i] != '_')
            stack_save_txt.push(txt[i]);
        if (txt[i] == '_' || i == txt.length() - 1)
        {
            while (!stack_save_txt.empty())
            {
                new_txt += stack_save_txt.top();
                stack_save_txt.pop();
            }
            if (i != txt.length() - 1)
                new_txt += "_";
        }
    }

    cout << new_txt;
}