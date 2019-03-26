#include <iostream>
#include <iterator>
#include <list>
using namespace std;
int main()
{
    int fn = 1;
    int n;
    char command;
    string txt;
    // int state = 1;
    list<string> editor;
    list<string>::iterator itr = editor.begin();
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> command;
        if (command == 'i')
        {

            cin >> txt;
            txt += " ";
            if (fn == 0)
            {
                // cout << " back ";
                if (itr != editor.end())
                    itr++;
                editor.insert(itr, txt);
                if (itr != editor.begin())
                    itr--; // back to origin point
                // cout << *itr;
            }
            else if (fn == 1)
            {
                // cout << " front ";
                editor.insert(itr, txt);
                if (itr != editor.begin())
                    itr--;
            }

            fn = 0;
        }
        else if (command == 'b')
        {

            if (!editor.empty())
            {
                if (fn == 0)
                { // BACK
                    editor.erase(itr);
                    if (next(itr) == editor.begin() && fn == 0)
                    {
                        cout << "poon";
                        itr++;
                        fn = 1;
                    }

                    // if(itr == editor.begin() && fn == 1)
                    else
                    {
                        if (fn != 1)
                        {
                            itr--;
                            fn = 0;
                        }
                    }
                }
                // else if(fn == 1){ // FRONT

                // }
                if (editor.empty())
                    fn = 1;
            }
        }
        else if (command == 'd')
        {
            if (!editor.empty())
            {
                if (itr == editor.begin())
                {
                    // cout << "2";
                    if (fn == 0)
                    { // BACK

                        if (itr != editor.end() && next(itr) != editor.end())
                        {
                            if (itr != editor.end())
                                itr++;
                            editor.erase(itr);
                            if (itr != editor.begin())
                                itr--;
                        }
                    }
                    else if (fn == 1)
                    { // FRONT
                        // cout << "hello";
                        editor.erase(itr);
                        if (itr != editor.end() && next(itr) != editor.end()) // ** next
                            itr++;
                        fn = 1;
                        if (editor.empty())
                        {
                            itr = editor.begin();
                        }
                    }
                }
                else
                {
                    // cout << "1";
                    if (itr != editor.end() && next(itr) != editor.end())
                    {
                        if (itr != editor.end())
                            itr++;
                        editor.erase(itr);
                        if (itr != editor.begin())
                            itr--;
                    }
                }
                if (editor.empty())
                    fn = 1;
            }
        }
        else if (command == 'l')
        {
            if (!editor.empty())
            {
                if (itr != editor.begin())
                {
                    itr--;
                    fn = 0; // BACK
                }

                else
                {
                    if (!editor.empty())
                        fn = 1; // FRONT
                }
            }
        }
        else if (command == 'r')
        {
            if (!editor.empty())
            {
                if (fn == 1)
                {
                    if (!editor.empty())
                        fn = 0;
                }
                else if (fn == 0)
                {
                    if (itr != editor.end() && next(itr) != editor.end())
                    {
                        itr++;
                    }
                }
            }
        }

        // cout << "##" << command << " " << fn << " " << *itr << " " << endl;

        // for (list<string>::iterator itrr = editor.begin(); itrr != editor.end(); itrr++)
        // {
        //     cout << *itrr << " ";
        // }
        // cout << endl;
    }

    for (list<string>::iterator itrr = editor.begin(); itrr != editor.end(); itrr++)
    {
        cout << *itrr;
    }
}