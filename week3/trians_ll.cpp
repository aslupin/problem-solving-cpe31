
#include <iostream>
using namespace std;
typedef int value;

struct ListNode
{
    value val;
    ListNode *next;
    ListNode *prev;
    ListNode(value val, ListNode *next = 0, ListNode *prev = 0) : val(val), next(next), prev(prev) {}
};

int main()
{
    int setter = 0, getter = 0, max_inp = 0;
    int n;
    char command;
    cin >> n;
    ListNode *container[100000] = {0};
    ListNode *tail[100000] = {0};

    for (int i = 0; i < n; i++)
    {
        cin >> command >> setter >> getter;

        if (max_inp < getter || i == 0)
            max_inp = getter;

        if (command == 'N')
        {
            ListNode *newNode = new ListNode(setter);
            if (container[getter - 1] == NULL)
            { // NO TRAIN IN THIS STATION.
                container[getter - 1] = newNode;
            }
            else
            { // HAVE ONE IN THIS STATION.
                tail[getter - 1]->next = newNode;
            }

            tail[getter - 1] = newNode;
        }
        else if (command == 'M' && (setter != getter))
        {
            if (container[getter - 1] == NULL)
            { // NO ONE IN GETTER'S STATION => DO LIKE COPY.
                container[getter - 1] = container[setter - 1];
            }
            else
            { // HAVE ONE IN GETTER'S STATION => PUSH BACK TO TAIL'S GETTER.
                tail[getter - 1]->next = container[setter - 1];
            }

            tail[getter - 1] = tail[setter - 1];

            // CLEAR SETTER'S STATION
            container[setter - 1] = 0;
            tail[setter - 1] = 0;
        }

        // ListNode *interval = container[getter - 1];
        // while (interval != NULL)
        // {
        //     cout << interval->val << " ";
        //     interval = interval->next;
        // }
        // cout << endl;
    }

    for (int i = 0; i < max_inp; i++)
    {
        if (container[i] != NULL)
        {
            ListNode *interval = container[i];
            while (interval != NULL)
            {
                cout << interval->val << endl;
                interval = interval->next;
            }
            // do
            // {
            //     cout << interval->val << endl;
            //     interval = interval->next;
            // } while (interval != container[i]);
        }
    }
}
