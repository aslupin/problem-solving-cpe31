#include <iostream>
using namespace std;

int main()
{
    int a[5] = {1, 2, 3, 4, 5};

    int *p = a;

    cout << *p << endl;
    cout << *(
                p + 3)
         << endl;

    p +=
        3;

    cout << *p << endl;
    cout << *(p - 1) << endl;

    int *q = &a[4];

    cout << q - p << endl;
}