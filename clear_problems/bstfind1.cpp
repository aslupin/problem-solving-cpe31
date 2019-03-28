#include <iostream>
using namespace std;

typedef int valueType;

struct Node
{
    valueType val;
    Node *left;
    Node *right;

    Node(valueType val, Node *left = 0, Node *right = 0)
        : val(val), left(left), right(right) {}
};

int main()
{
    bool init = true;
    int n;
    int command, operand;
    Node *bst = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> command >> operand;
        if (command == 1)
        { // INSERT
            bool r = false, l = false;
            if (init)
            {
                bst = new Node(operand);
                init = false;
            }

            else
            {
                Node *itr = bst;
                while (itr != NULL)
                {
                    if (operand < itr->val)
                    {
                        if (itr->left == NULL)
                        {
                            l = true;
                            break;
                        }

                        itr = itr->left;
                    }
                    else if (operand > itr->val)
                    {
                        if (itr->right == NULL)
                        {
                            r = true;
                            break;
                        }
                        itr = itr->right;
                    }
                }
                if (r)
                    itr->right = new Node(operand);
                else if (l)
                    itr->left = new Node(operand);
            }
        }
        else if (command == 2)
        {
            Node *itr = bst;
            while (itr != NULL)
            {
                if (operand == itr->val)
                    break;
                if (operand < itr->val)
                    itr = itr->left;
                else if (operand > itr->val)
                    itr = itr->right;
            }
            if (itr == NULL)
                cout << 0 << endl;
            else if (itr->val == operand)
                cout << 1 << endl;
                }
    }
    // Node *p = bst;

    // while (p != NULL)
    // {
    //     cout << p->val;
    //     p = p->right;
    // }
}