#include <iostream>
#include <stack>
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

void dfs(Node *itr, int layer)
{
    if (itr != NULL)
    {
        dfs(itr->right, layer + 1);
        for (int i = 1; i <= layer; i++)
            cout << "...";
        cout << "* ";
        cout << itr->val << endl;
        dfs(itr->left, layer + 1);
    }
}

int main()
{
    bool init = true;
    int n;
    int command, operand;
    Node *bst = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> operand;
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

    dfs(bst, 0);
}