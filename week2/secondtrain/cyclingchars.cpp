#include <iostream>
using namespace std;

int main()
{
    char txt[100];
    char txt_encoded[100];
    cin >> txt;
    // cout << (int)txt[0];
    for (int i = 0; txt[i] != '\0'; i++)
    {
        int ascii_encoded = ((int)txt[i]);
        // cout << ascii_encoded;
        if (ascii_encoded == 119)
            ascii_encoded = 97;
        else if (ascii_encoded == 120)
            ascii_encoded = 98;
        else if (ascii_encoded == 121)
            ascii_encoded = 99;
        else if (ascii_encoded == 122)
            ascii_encoded = 100;
        else
            ascii_encoded = ((int)txt[i] + 4);
        txt_encoded[i] = (char)ascii_encoded;
        // cout << ascii_encoded;
    }

    cout << txt_encoded;
    // char txt_encoded[100];
    // cin >> txt;

    // txt_encoded[i] = (char)((int)txt[i] + 4);

    // cout << txt_encoded;
}