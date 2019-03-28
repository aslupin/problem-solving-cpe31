#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<string> rec;
    int cursor = 0;
    int n;
    bool isBack = false;
    char command;
    string operand;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> command;
        if (command == 'i')
        {
            cin >> operand;
            if (isBack)
            {
                rec.insert(rec.begin() + (++cursor), operand);
            }
            else
            {
                rec.insert(rec.begin() + cursor, operand);
            }

            isBack = true;
        }
        else if (command == 'l')
        {
            if (cursor > 0)
                cursor--;
            else
            {
                isBack = false;
            }
        }
        else if (command == 'r')
        {

            if (!rec.empty())
            {
                if (isBack)
                {
                    if (cursor != rec.size() - 1)
                        cursor++;
                    isBack = true;
                }
                else
                {
                    isBack = true;
                }
            }
        }
        else if (command == 'd')
        {
            if (!rec.empty())
            {
                if (isBack)
                {
                    if (cursor != rec.size() - 1)
                    {
                        rec.erase(rec.begin() + cursor + 1);
                    }
                }
                else
                {
                    rec.erase(rec.begin() + cursor);
                }
                if (rec.empty())
                    isBack = false;
            }
        }
        else if (command == 'b')
        {
            if (!rec.empty())
            {
                if (isBack)
                {
                    rec.erase(rec.begin() + cursor);

                    if (cursor != 0)
                    {
                        cursor--;
                    }
                    else
                    {
                        isBack = false;
                    }
                }
                if (rec.empty())
                    isBack = false;
            }
        }
    }
    for (int i = 0; i < rec.size(); i++)
        cout << rec[i] << " ";
}