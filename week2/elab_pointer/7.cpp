#include <iostream>
using namespace std;

void remove_quotes(char *src, char *dest)
{

    int i = 0;
    int j = 0;
    while (*(src + i) != '\0')
    {
        if (*(src + i) == '\"' || *(src + i) == '\'')
        {
            i++;
        }
        else
        {
            cout << j << ' ' << i << endl;
            *(dest + j) = *(src + i);
            i++;
            j++;
        }
    }

    *(dest + (j)) = '\0';
}

int main()
{
    char st[5];
    char out[5];
    int l;

    cin.getline(st, 5);
    remove_quotes(st, out);

    cout << out << endl;
}