#include <iostream>
#include<bits/stdc++.h>
#include <math.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node()
    {
        data = 0;
        left = NULL;
        right = NULL;
    }
};

Node *getnode(int data)
{
    Node *n = new Node;
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

bool IsStrictBT(Node *root)
{
    if (root != NULL)
    {
        if ((root->left == NULL && root->right == NULL) || (root->left != NULL && root->right != NULL))
        {
            if (IsStrictBT(root->left) && IsStrictBT(root->right))
                return true;
            else
                return false;
        }
        else
            return false;
    }
    else
        return true;
}

bool IsBST(Node *root,int rootdata)
{
    if (root != NULL)
    {
        rootdata=root->data;
        if(root->left!=NULL && root->left->data < rootdata)
        {
            rootdata=root->left->data;
            return (IsBST(root->left,rootdata));
        }
        else if(root->right!=NULL && root->right->data > rootdata)
        {
            rootdata=root->right->data;
            return (IsBST(root->right,rootdata));
        }
        else return false;
    //     if (root->left != NULL && root->right != NULL)
    //     {
    //         if (root->left->data < root->data && root->right->data > root->data)
    //         {
    //             if (IsBST(root->left) && (IsBST(root->right)))
    //                 return true;
    //             else
    //                 return false;
    //         }
    //         else
    //             return false;
    //     }
    //     else if (root->left == NULL && root->right == NULL)
    //         return true;
    //     else if (root->left != NULL && root->right == NULL)
    //     {
    //         if (root->data > root->left->data)
    //             if (IsBST(root->left))
    //                 return true;
    //             else
    //                 return false;
    //         else
    //             return false;
    //     }
    //     else
    //     {
    //         if (root->data < root->right->data)
    //             if (IsBST(root->right))
    //                 return true;
    //             else
    //                 return false;
    //         else
    //             return false;
    //     }
    // }
    else
        return true;
}
queue<Node*>q;
bool IsCompleteBT(Node *root)
{
    Node*n=q.front();
        if (n->left!=NULL&&n->right!=NULL)
        {
            q.push(n->left);
            q.push(n->right);
            if (IsCompleteBT(n->left))
            {
                if(IsCompleteBT(n->right))
                return true;
                else
                return false;
            }
            else 
            return false;
        }
        else if (n->left!=NULL&&n->right==NULL)
        {
            q.push(n->left);
            if (IsCompleteBT(n->left))
            return true;
            else 
            return false;
        }
        else if (n->left==NULL && n->right!=NULL)
        {
            return false;
        }
        else
        {
            q.pop();
            if(IsCompleteBT(q.front()))
            return true;
            else 
            return false;
        }
}
int height(Node *root)
{
    if (root == NULL)
        return 0;
    else
    {
        int l = height(root->left);
        int r = height(root->right);
        if (l > r)
            return l + 1;
        else
            return r + 1;
    }
}
int numbernodes(Node *root1)
{
    if (root1 == NULL)
        return 0;
    else
        return (numbernodes(root1->left) + numbernodes(root1->right) + 1);
}

bool IsPerfectBT(Node *root)
{
    if (root != NULL)
    {
        //cout<<numbernodes(root)<<endl;
        //cout<<height(root)<<endl;
        if (numbernodes(root) == pow(2, height(root)) - 1)
            return true;
        else
            return false;
    }
    else
        return true;
}

int main()
{
    Node *root = NULL;
    root = getnode(34);
    root->left = getnode(23);
    root->right = getnode(56);

    root->left->left = getnode(47);
    root->left->right = getnode(50);
    root->right->left = getnode(55);
    root->left->left->left = getnode(48);
    
    //root->right->right=getnode(40);
    if (IsStrictBT(root))
        cout << "Is a Strict Binary Tree" << endl;
    else
        cout << "Not a Strict Binary Tree" << endl;
    if (IsBST(root))
        cout << "Is a Binary search Tree" << endl;
    else
        cout << "Not a Binary search Tree" << endl;
    if (IsCompleteBT(root))
        cout << "Is a Complete Binary Tree" << endl;
    else
        cout << "Not a Complete Binary Tree" << endl;
    if (IsPerfectBT(root))
        cout << "Is a Perfect Binary Tree" << endl;
    else
        cout << "Not a Perfect Binary Tree" << endl;
}