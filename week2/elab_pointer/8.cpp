#include <iostream>
using namespace std;

char *write_chars(char *dest, const char *st)
{

    int i = 0;
    while (*(st + i) != '\0')
    {
        *(dest + i) = *(st + i);
        i++;
    }

    return dest;
}

void escape(char *src, char *dest)
{

    int i = 0;
    int j = 0;
    while (*(src + i) != '\0')
    {
        if (*(src + i) == '>')
        {

            write_chars(dest + j, "&gt;");

            j += 4;
            i++;
        }
        else if (*(src + i) == '<')
        {
            write_chars(dest + j, "&lt;");

            j += 4;
            i++;
        }
        else if (*(src + i) == '\"')
        {
            write_chars(dest + j, "&quot;");
            j += 6;
            i++;
        }
        else
        {
            *(dest + j) = *(src + i);

            j++;
            i++;
        }
    }
    *(dest + j) = '\0';
}

int main()
{
    char st[1000];
    char out[1000];
    int l;

    cin.getline(st, 1000);
    escape(st, out);

    cout << out << endl;
}