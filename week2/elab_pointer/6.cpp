#include <iostream>
using namespace std;

void copy_string(char *src, char *dest)
{

    int i = 0;
    while (*(src + i) != '\0')
    {
        *(dest + i) = *(src + i);
        i++;
    }
}

int main()
{
    char st1[1000];
    char st2[1000];

    cin.getline(st1, 1000);
    copy_string(st1, st2);

    cout << st2 << endl;
}