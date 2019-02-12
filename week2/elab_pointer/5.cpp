#include <iostream>
using namespace std;

int count_char(char *st, char c)
{

    int count = 0;
    int i = 0;
    while (*(st + i) != '\0')
    {
        if (*(st + i) == c)
        {
            count++;
                }
        i++;
    }
    return count;
}

int main()
{
    char st[1000];

    cin.getline(st, 1000);

    cout << "space: " << count_char(st, ' ') << endl;
    cout << "dot: " << count_char(st, '.') << endl;
    cout << "semi: " << count_char(st, ';') << endl;
}