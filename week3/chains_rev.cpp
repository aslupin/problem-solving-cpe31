#include <iostream>
#include <list>
#include <iterator>
#include <stdio.h>
using namespace std;
typedef int value;
struct ListNode
{
    value val;
    ListNode *next;
    ListNode *prev;

    //https://stackoverflow.com/questions/1127396/struct-constructor-in-c
    //https://en.cppreference.com/w/cpp/language/initializer_list
    //initializer_list

    ListNode(value val, ListNode *next = 0, ListNode *prev = 0)
        : val(val), next(next), prev(prev) {}
};

int main()
{

    int l, n, each_list;
    int target;
    char command;
    // cin >> l >> n;
    scanf("%d %d", &l, &n);

    list<int> dna, pos;
    int size_dna = 0;

    ListNode *node[999999];
    int count = 0;
    for (int i = 0; i < l; i++)
    {
        // cin >> each_list;
        scanf("%d", &each_list);
        ListNode *beforeNode = 0;
        for (int j = 0; j < each_list; j++)
        {
            node[count + j] = new ListNode(count + j);
            if (beforeNode != NULL)
            {
                node[count + j]->prev = beforeNode;
                beforeNode->next = node[count + j];
            }
            beforeNode = node[count + j];
        }
        count += each_list;
    }

    ListNode *robot = node[0];

    for (int i = 0; i < n; i++)
    {
        // cin >> command;
        scanf(" %c", &command);

        switch (command)
        {
        case 'F':
        {
            if (robot->next != NULL)
                robot = robot->next;
            break;
        }
        case 'B':
        {
            if (robot->prev != NULL)
                robot = robot->prev;
            break;
        }
        case 'C':
        {
            // cin >> target;
            scanf("%d", &target);

            if (node[target - 1]->next != NULL)
            {
                // cout << ">>>" << endl;
                // CUT
                if (robot->next != NULL)
                {
                    ListNode *cut = robot->next;
                    cut->prev = NULL;
                }

                robot->next = NULL;

                //COMBINE
                node[target - 1]->prev = robot;
                robot->next = node[target - 1];
                robot = robot->next;
            }
            else if (node[target - 1]->prev != NULL)
            {

                // CUT
                if (robot->next != NULL)
                {
                    ListNode *cut = robot->next;
                    cut->prev = NULL;
                }
                robot->next = NULL;

                //REVERSE
                // ListNode *r = node[target - 1];
                // while (r != NULL)
                // {

                //     ListNode *old_next = r->next;
                //     r->next = r->prev;
                //     r->prev = old_next;

                //     r = r->next;
                // }

                //COMBINE
                node[target - 1]->next = node[target - 1]->prev;
                node[target - 1]->prev = robot;
                robot->next = node[target - 1];
                robot = robot->next;
            }
            else
            {

                //CUT
                if (robot->next != NULL)
                {
                    ListNode *cut = robot->next;
                    cut->prev = NULL;
                }

                robot->next = NULL;
                //COMBINE
                node[target - 1]->prev = robot;
                robot->next = node[target - 1];
                robot = robot->next;
            }
            break;
        }

        default:
            break;
        }

        // Fix node's after robot direction
        if (robot->next != NULL) // have node
        {
            ListNode *afterNode = robot->next;
            if (afterNode->next == robot)
            {
                ListNode *tmp = afterNode->next;
                afterNode->next = afterNode->prev;
                afterNode->prev = tmp;
            }
        }

        pos.push_back(robot->val + 1);
    }
    while (!pos.empty())
    {
        // cout << pos.front() << endl;
        printf("%d\n", pos.front());
        pos.pop_front();
    }
}
