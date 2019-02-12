
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

    valueType get_front();
    void delete_front();

    bool is_empty();
};

/* Again, unrelated functions are hidden. */

valueType LinkedList::get_front()
{
    ListNode *front = header->next;
    return front->val;
}

void LinkedList::delete_front()
{
    if (is_empty())
    {
        throw "Error: list is empty.";
    }
    ListNode *front = header->next;

    header = front->next;

    delete front;
}

int main()
{
    LinkedList l1;

    l1.append(10);
    cout << l1.get_front() << endl;
    l1.insert_front(20);
    cout << l1.get_front() << endl;
    l1.delete_front();
    cout << l1.get_front() << endl;
    cout << (l1.is_empty() ? "yes" : "no") << endl;
    l1.delete_front();
    cout << (l1.is_empty() ? "yes" : "no") << endl;
    l1.append(100);
    cout << l1.get_front() << endl;
    l1.insert_front(200);
    cout << l1.get_front() << endl;
    l1.append(1000);
    l1.print_list();
    l1.delete_front();
    l1.delete_front();
    l1.print_list();
    l1.delete_front();
    cout << (l1.is_empty() ? "yes" : "no") << endl;
}