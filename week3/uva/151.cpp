#include <iostream>
#include <list>
using namespace std;

typedef int valueType;

struct ListNode
{
    valueType val;
    ListNode *next;
    ListNode *prev;

    ListNode(valueType val, ListNode *next = 0, ListNode *prev = 0)
        : val(val), next(next), prev(prev) {}
};

int getRegion(int n = 13, int m = 5)
{
    ListNode *node[n];
    ListNode *tmp = 0;
    ListNode *header = 0;
    for (int i = 0; i < n; i++)
    {
        node[i] = new ListNode(i);
        if (i == 0)
        {
            header = node[i];
            node[i]->next = node[i];
            node[i]->prev = node[i];
        }
        else if (i == n - 1)
        {
            header->prev = node[i];
            node[i]->next = header;
            tmp->next = node[i];
            node[i]->prev = tmp;
        }
        else
        {
            tmp->next = node[i];
            node[i]->prev = tmp;
        }

        tmp = node[i];
    }
    ListNode *walk = node[0];
    ListNode *savepoint = walk;
    // for (int i = 0; i < n - 1; i++)
    while (1)
    {
        savepoint = walk;
        ListNode *deleteNode = walk;
        // cout << deleteNode->val + 1 << " " << endl;
        // DELETE NODE
        deleteNode->prev->next = deleteNode->next;
        deleteNode->next->prev = deleteNode->prev;

        for (int j = 1; j <= m; j++)
        {
            walk = walk->next;
        }

        if (walk == savepoint)
            break;
    }

    if (walk->val + 1 == 13)
        return 1;
    else
        return 0;
}
int main()
{
    int n;
    list<int> ans;

    do
    {
        cin >> n;

        if (n != 0)
        {
            int m = 1;
            while (1)
            {

                if (getRegion(n, m))
                {
                    ans.push_back(m);
                    break;
                }
                m++;
            }
        }

    } while (n != 0);

    for (list<int>::iterator itr = ans.begin(); itr != ans.end(); itr++)
    {
        cout << *itr << endl;
    }
}
