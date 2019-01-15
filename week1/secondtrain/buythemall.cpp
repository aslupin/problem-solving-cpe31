#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int type_item[3][2];
    int n;
    int itemInStore;
    cin >> type_item[0][0] >> type_item[1][0] >> type_item[2][0];
    type_item[0][1] = type_item[1][1] = type_item[2][1] = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> itemInStore;
        type_item[itemInStore - 1][1] += type_item[itemInStore - 1][0];
    }
    cout << min(min(type_item[0][1], type_item[1][1]), type_item[2][1]);
}