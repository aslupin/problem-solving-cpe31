#include <iostream>
using namespace std;
int main()
{
    int ignore, Q;
    bool isK = 0; // Focus at K
    cin >> Q;
    while (1)
    {
        cin >> ignore;
        if (ignore == 0)
            break;
        isK = !isK;
    }
    if (Q % 2 == isK)
        cout << "K";
    else
        cout << "C";
}