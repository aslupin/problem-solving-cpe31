#include <list>
#include <iostream>
using namespace std;

int main()
{
    list<int> ic;
    int n, in_value;
    string command;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> command;

        if (command == "li")
        {
            cin >> in_value;
            ic.push_front(in_value);
        }
        else if (command == "ri")
        {
            cin >> in_value;
            ic.push_back(in_value);
        }
        else if (command == "lr")
        {
            if (!ic.empty())
            {
                int front = ic.front();
                ic.pop_front();
                ic.push_back(front);
            }
        }
        else if (command == "rr")
        {
            if (!ic.empty())
            {
                int back = ic.back();
                ic.pop_back();
                ic.push_front(back);
            }
        }
    }
    for (list<int>::iterator itr = ic.begin(); itr != ic.end(); itr++)
        cout << *itr << endl;
}