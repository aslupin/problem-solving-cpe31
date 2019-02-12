#include <iostream>
#include <list>
// #include <vector>
#include <iterator>
using namespace std;

int main()
{
    // typedef pair<int, int> ii;
    // vector<ii> box;

    int l, n, each_list;
    int target;
    char command;
    cin >> l >> n;
    int ht[l][2];
    list<int> dna[l], pos;

    for (int i = 0, count = 0; i < l; i++, count += each_list)
    {
        cin >> each_list;
        for (int j = 0; j < each_list; j++)
        {
            dna[i].push_back(j + count);

            if (j == 0)
                ht[i][0] = j + count;
            if (j == each_list - 1)
                ht[i][1] = j + count;
        }
    }

    list<int>::iterator robot = dna[0].begin();

    for (int i = 0; i < n; i++)
    {
        cin >> command;
        if (command == 'F')
        {
            if (robot != dna[0].end())
                robot++;
        }
        else if (command == 'B')
        {
            if (robot != dna[0].begin())
                robot--;
        }
        else if (command == 'C')
        {
            cin >> target;
            int i = 0, ll_right = 1;
            for (; i < l; i++)
            {
                if (*dna[i].begin() == target - 1)
                {
                    ll_right = 1;
                    break;
                }
                if (*dna[i].end() == target - 1)
                {
                    ll_right = 0;
                    break;
                }
            }
            //CUT
            dna[0].erase(next(robot, 1), dna[0].end());

            // list<int>::iterator it = find(dna[0].begin(), dna[0].end(), )
        }

        pos.push_back(*robot + 1);
    }

    for (list<int>::iterator itr = pos.begin(); itr != pos.end(); itr++)
    {
        cout << *itr << endl;
    }
}
