#include <iostream>
#include <stdio.h>
using namespace std;

typedef int valueType;

struct Node
{
    valueType val;
    valueType size;
    Node *left;
    Node *right;

    Node(valueType val, valueType size = 0, Node *left = 0, Node *right = 0)
        : val(val), size(size), left(left), right(right) {}
};
void printTree(Node *itr, int layer)
{
    if (itr != NULL)
    {
        printTree(itr->right, layer + 1);
        for (int i = 1; i <= layer; i++)
            cout << "...";
        cout << "* ";
        cout << itr->val << ", " << itr->size << endl;
        printTree(itr->left, layer + 1);
    }
}
int dfs(Node *itr, int x)
{
    if (itr != NULL)
    {
        int r = 0, l = 0;
        if (itr->val >= x)
            l = dfs(itr->left, x);
        if (itr->val >= x && itr->right != NULL)
            r = itr->right->size;
        else
            r = dfs(itr->right, x);

        if (itr->val > x)
            return r + l + 1;
        else
            return r + l;
    }
    else
        return 0;
}

int main()
{
    bool init = true;
    int n;
    int operand;
    char command;
    Node *bst = 0;
    // cin >> n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf(" %c %d", &command, &operand);
        // cin >> command >> operand;
        switch (command)
        {
        case '1':
        {
            bool r = false, l = false;
            if (init)
            {

                bst = new Node(operand);
                bst->size += 1;
                init = false;
            }

            else
            {
                Node *itr = bst;
                while (itr != NULL)
                {
                    itr->size += 1;
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
                {
                    itr->right = new Node(operand);
                    itr->right->size += 1;
                }

                else if (l)
                {
                    itr->left = new Node(operand);
                    itr->left->size += 1;
                }
            }
            break;
        }
        case '2':
        {
            int cc = dfs(bst, operand);
            printf("%d\n", cc);
            break;
        }
        default:
            break;
        }
    }
    // printTree(bst, 0);
}