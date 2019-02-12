#include <stdio.h>
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
    // cin >> n;
    scanf("%d", &n);
    ListNode *container[100000] = {0};
    for (int i = 0; i < n; i++)
    {

        scanf(" %c %d %d", &command, &setter, &getter);

        if (max_inp < getter || i == 0)
            max_inp = getter;

        switch (command)
        {
        case 'N':
        {
            ListNode *newNode = new ListNode(setter);
            if (container[getter - 1] == NULL)
            { // NO TRAIN IN THIS STATION.
                container[getter - 1] = newNode;
            }
            else
            { // HAVE ONE IN THIS STATION.
                container[getter - 1]->prev->next = newNode;
                newNode->prev = container[getter - 1]->prev;
            }
            newNode->next = container[getter - 1];
            container[getter - 1]->prev = newNode;
            break;
        }

        case 'M':
        {
            if (container[getter - 1] == NULL)
            { // NO ONE IN GETTER'S STATION => DO LIKE COPY.
                if (container[setter - 1] != NULL)
                    container[getter - 1] = container[setter - 1];
            }
            else
            { // HAVE ONE IN GETTER'S STATION => PUSH BACK TO TAIL'S GETTER.
                if (container[setter - 1] != NULL)
                {
                    container[getter - 1]->prev->next = container[setter - 1];
                    container[setter - 1]->prev->next = container[getter - 1];
                    ListNode *tailGetter = container[getter - 1]->prev;
                    container[getter - 1]->prev = container[setter - 1]->prev;
                    container[setter - 1]->prev = tailGetter;
                }
            }

            // CLEAR SETTER'S STATION
            container[setter - 1] = 0;
        }
        }
        // if (command == 'N')
        // {
        //     ListNode *newNode = new ListNode(setter);
        //     if (container[getter - 1] == NULL)
        //     { // NO TRAIN IN THIS STATION.
        //         container[getter - 1] = newNode;
        //     }
        //     else
        //     { // HAVE ONE IN THIS STATION.
        //         container[getter - 1]->prev->next = newNode;
        //         newNode->prev = container[getter - 1]->prev;
        //     }
        //     newNode->next = container[getter - 1];
        //     container[getter - 1]->prev = newNode;
        // }
        // else if (command == 'M' && (setter != getter))
        // {
        //     if (container[getter - 1] == NULL)
        //     { // NO ONE IN GETTER'S STATION => DO LIKE COPY.
        //         if (container[setter - 1] != NULL)
        //             container[getter - 1] = container[setter - 1];
        //     }
        //     else
        //     { // HAVE ONE IN GETTER'S STATION => PUSH BACK TO TAIL'S GETTER.
        //         if (container[setter - 1] != NULL)
        //         {
        //             container[getter - 1]->prev->next = container[setter - 1];
        //             container[setter - 1]->prev->next = container[getter - 1];
        //             ListNode *tailGetter = container[getter - 1]->prev;
        //             container[getter - 1]->prev = container[setter - 1]->prev;
        //             container[setter - 1]->prev = tailGetter;
        //         }
        //     }

        //     // CLEAR SETTER'S STATION
        //     container[setter - 1] = 0;
        // }
    }

    for (int i = 0; i < max_inp; i++)
    {
        if (container[i] != NULL)
        {
            ListNode *interval = container[i];
            do
            {
                cout << interval->val << endl;
                interval = interval->next;
            } while (interval != container[i]);
        }
    }
}
