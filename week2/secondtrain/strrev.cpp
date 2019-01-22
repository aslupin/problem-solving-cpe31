#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<char> stack_save_txt;
    string txt;
    cin >> txt;
    for (int i = 0; i < txt.length(); i++)
    {
        stack_save_txt.push(txt[i]);
    }
    while (!stack_save_txt.empty())
    {
        cout << stack_save_txt.top();
        stack_save_txt.pop();
    }
}