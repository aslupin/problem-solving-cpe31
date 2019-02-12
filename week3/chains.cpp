#include <iostream>
#include <list>
#include <stdio.h>
#include <iterator>
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

    for (int i = 0; i < l; i++)
    {
        // cin >> each_list;
        scanf("%d", &each_list);
        size_dna += each_list;
        dna.push_back(each_list);
    }

    ListNode *node[size_dna];
    int count = 0;
    for (list<int>::iterator itr = dna.begin(); itr != dna.end(); count += *itr, itr++)
    {
        ListNode *beforeNode = 0;
        for (int j = 0; j < *itr; j++)
        {
            node[count + j] = new ListNode(count + j);
            if (beforeNode != NULL)
            {
                node[count + j]->prev = beforeNode;
                beforeNode->next = node[count + j];
            }
            beforeNode = node[count + j];
        }
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
                ListNode *r = node[target - 1];
                while (r != NULL)
                {

                    ListNode *old_next = r->next;
                    r->next = r->prev;
                    r->prev = old_next;

                    r = r->next;
                }

                //COMBINE
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
        pos.push_back(robot->val + 1);
    }
    while (!pos.empty())
    {
        printf("%d\n", pos.front());
        pos.pop_front();
    }
}
