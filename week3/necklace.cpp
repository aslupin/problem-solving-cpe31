#include <iostream>
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

int main()
{

    int n, front, back;
    cin >> n;

    ListNode *node[n];

    for (int i = 0; i < n; i++)
    {
        node[i] = new ListNode(i);
    }

    for (int i = 0; i < n - 1; i++)
    {
        cin >> back >> front;

        if (node[front - 1]->next != NULL) // WHEN NODE-FORNT IS LIST.
        {
            ListNode *tailBackNode = node[back - 1];
            while (tailBackNode != NULL)
            {
                if (tailBackNode->next == NULL) // FOUND TAIL.
                    break;
                tailBackNode = tailBackNode->next;
            }
            // INSERT IN FRONT-LIST
            node[front - 1]->next->prev = tailBackNode;
            tailBackNode->next = node[front - 1]->next;
        }

        node[front - 1]->next = node[back - 1];
        node[back - 1]->prev = node[front - 1];
    }

    // FIND HEADER NODE BY PREV == NULL
    ListNode *header = node[0];
    while (header->prev != NULL)
    {
        header = header->prev;
    }
    // INTERVAL
    while (header != 0)
    {
        cout << header->val + 1 << " ";
        header = header->next;
    }
}
