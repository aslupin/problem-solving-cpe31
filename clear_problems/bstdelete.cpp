#include <iostream>
#include <stdio.h>
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

// void dfs(Node *itr, int layer)
// {
//     if (itr != NULL)
//     {
//         dfs(itr->right, layer + 1);
//         for (int i = 1; i <= layer; i++)
//             cout << "...";
//         cout << "* ";
//         cout << itr->val;
//         if (itr->left == NULL)
//             cout << " [ 0, ";
//         else
//             cout << " [ 1, ";
//         if (itr->right == NULL)
//             cout << "0 ]";
//         else
//             cout << "1 ]";
//         cout << endl;
//         dfs(itr->left, layer + 1);
//     }
// }

// Node *delNode(Node *root, int val)
// {
//     if (root == NULL)
//         return root;
//     else if (val < root->val)
//         root->left = delNode(root->left, val);
//     else if (val > root->val)
//         root->right = delNode(root->right, val);
//     // Wohoo... I found you, Get ready to be deleted
//     else
//     {
//         // Case 1:  No child
//         if (root->left == NULL && root->right == NULL)
//         {
//             delete root;
//             root = NULL;
//         }
//         //Case 2: One child
//         else if (root->left == NULL)
//         {
//             Node *temp = root;
//             root = root->right;
//             delete temp;
//         }
//         else if (root->right == NULL)
//         {
//             Node *temp = root;
//             root = root->left;
//             delete temp;
//         }
//         // case 3: 2 children
//         else
//         {
//             Node *minNode = root->right;
//             while (minNode->left != NULL)
//                 minNode = minNode->left;
//             // Node *temp = FindMin(root->right);
//             Node *temp = minNode;
//             root->val = temp->val;
//             root->right = delNode(root->right, temp->val);
//         }
//     }
//     return root;
// }

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
        if (command == '1')
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
        else if (command == '2')
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
                printf("0\n");

            else if (itr->val == operand)
                printf("1\n");
        }
        else if (command == '3')
        {

            // bst = delNode(bst, operand);
            // if (bst == NULL)
            //     init = 1;

            // Node *minTree = delNodeBst(bst, operand);

            bool isR = false;
            bool isL = false;
            Node *itr = bst;
            Node *motherNode = bst;
            while (itr != NULL)
            {
                if (operand == itr->val)
                    break;
                if (operand < itr->val)
                {
                    motherNode = itr;
                    itr = itr->left;
                    isL = true;
                    isR = false;
                }
                else if (operand > itr->val)
                {
                    motherNode = itr;
                    itr = itr->right;
                    isL = false;
                    isR = true;
                }
            }

            if (itr != NULL)
            {

                if (itr->left == NULL && itr->right == NULL)
                {
                    if (isL)
                        motherNode->left = NULL;
                    if (isR)
                        motherNode->right = NULL;
                    if (!isL && !isR)
                    {
                        init = true;
                        bst = NULL;
                    }
                }
                else if (itr->left != NULL && itr->right != NULL)
                {
                    int minimum = operand;
                    Node *minR = itr->right;
                    Node *momMinR = itr;
                    while (minR->left != NULL)
                    {
                        momMinR = minR;
                        minR = minR->left;
                    }

                    if (minR->right == NULL)
                    {
                        itr->val = minR->val;
                        if (momMinR != itr)
                            momMinR->left = NULL;
                        else
                            momMinR->right = NULL;
                    }
                    else
                    {
                        itr->val = minR->val;

                        if (momMinR == itr)
                            itr->right = minR->right;
                        else
                            momMinR->left = minR->right;
                    }
                }
                else
                {
                    if (isL)
                    {
                        if (itr->right != NULL)
                            motherNode->left = itr->right;
                        else if (itr->left != NULL)
                            motherNode->left = itr->left;
                    }
                    else if (isR)
                    {
                        if (itr->left != NULL)
                            motherNode->right = itr->left;
                        else if (itr->right != NULL)
                            motherNode->right = itr->right;
                    }
                    else if (!isL && !isR)
                    {
                        if (itr->left != NULL)
                            bst = itr->left;
                        else if (itr->right != NULL)
                            bst = itr->right;
                    }
                }
            }

            if (bst == NULL)
            {
                init = true;
            }
        }
    }
    // cout << endl;
    // dfs(bst, 0);
}