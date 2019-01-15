#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int student[n];
    for (int i = 0; i < n; i++)
    {
        cin >> student[i];
    }
    for (int i = 0; i < n; i++)
    {
        int counting = 0;
        for (int j = 0; j < n; j++)
        {
            if (i != j && student[i] < student[j])
            {
                counting += 1;
            }
        }
        cout << counting << endl;
    }
}