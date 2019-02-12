#include <iostream>

using namespace std;

typedef int valueType;

struct ListNode
{
    valueType val;
    ListNode *next;

    ListNode(valueType val, ListNode *next = 0)
        : val(val), next(next) {}
};

class LinkedList
{
  private:
    ListNode *header;
    ListNode *tail;
    void free_list();

  public:
    LinkedList();
    ~LinkedList();
    void print_list();
    void insert_front(valueType x);
    void append(valueType x);
};

LinkedList::LinkedList()
{
    cout << 'p';
}

/* To save space, functions ~LinkedList, print_list and free_list are hidden. */

void LinkedList::append(valueType x)
{

    ListNode *appendNode = new ListNode(x);
    tail->next = appendNode;
    tail = appendNode;
}

void LinkedList::insert_front(valueType x)
{

    ListNode *pushNode = new ListNode(x);
    pushNode->next = header->next;
    header->next = pushNode;
}

int main()
{
    LinkedList list;
    int t;

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int dir, val;
        cin >> dir >> val;
        if (dir == 1)
        {
            list.insert_front(val);
        }
        else
        {
            list.append(val);
        }
    }
    list.print_list();
}