#include <iostream>
#include <stdio.h>
using namespace std;

typedef int valueType;

struct Bogie
{
    valueType value;
    Bogie *next;

    Bogie(valueType value, Bogie *next = 0)
        : value(value), next(next) {}
};

class LinkedList
{
private:
public:
    Bogie *header;
    Bogie *tail;
    LinkedList();
    void show_list();
    void insert_front(valueType a);
    void Delete(valueType act);
    void Append(valueType a);
};

LinkedList::LinkedList()
{
    header = new Bogie(0);
    tail = header;
}

void LinkedList::Append(valueType a)
{
    Bogie *newnode = new Bogie(a);
    tail->next = newnode;
    newnode->next = NULL;
    tail = newnode;
    header->value++;
}
void LinkedList::show_list()
{
    Bogie *node = header->next;
    while (node != NULL)
    {
        // cout << node -> value << endl;
        printf("%d\n", node->value);
        node = node->next;
    }
}

LinkedList train[110000];
int main()
{
    char x;
    int act, i, j, k = 0;
    long int n;
    // cin >>act;
    scanf("%d", &act);
    while (k < act)
    {
        // cin>>x;
        scanf(" %c", &x);

        if (x == 'M')
        {
            scanf("%d %d", &i, &j);
            // cin>>i;
            // cin>>j;
            if (train[i].header == train[i].tail)
            {
                continue;
            }
            train[j].tail->next = train[i].header->next;
            train[j].tail = train[i].tail;
            train[i].header->value = 0;
            train[i].header->next = NULL;
            train[i].tail = train[i].header;
        }
        else if (x == 'N')
        {
            scanf("%d %d", &n, &i);
            // cin>>n;
            // cin>>i;
            train[i].Append(n);
        }
        k++;
    }
    for (int i = 1; i < 100000; i++)
    {
        train[i].show_list();
    }
    return 0;
}