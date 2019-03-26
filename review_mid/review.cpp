#include <iostream>
#include <iterator>
#include <list>
using namespace std;

int testStatic(int a)
{
    static int hello = a;
    cout << hello << " ";
}

int main()
{
    for (int i = 1; i < 10; i++)
        testStatic(i);
}