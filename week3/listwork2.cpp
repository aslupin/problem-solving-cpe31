#include <iostream>
#include <list>
#include <iterator>

using namespace std;
int main()
{
    list<int> ll;
    int n, operand;
    char command;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> command >> operand;
        if (command == 'I')
        {
            ll.push_front(operand);
        }
        else if (command == 'A')
        {
            ll.push_back(operand);
        }
        else if (command == 'D')
        {
            // cout << 's' << ll.size() << 'o' << operand << endl;
            if (!ll.empty() && operand <= ll.size())
            {
                // cout << operand << endl;

                list<int>::iterator it = ll.begin();
                advance(it, operand - 1);
                ll.erase(it);
            }
        }
    }
    for (list<int>::iterator itr = ll.begin(); itr != ll.end(); itr++)
    {
        cout << *itr << endl;
    }
}