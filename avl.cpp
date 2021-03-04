#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* left;
        Node* right;
    Node()
    {
        data=0;
        left=NULL;
        right=NULL;
    }
};

Node* getnode(int da)
{
    Node* n=new Node;
    n->data=da;
    n->left=NULL;
    n->right=NULL;
    return n;
}

Node* insert(Node* root1, int dat)
{
    if (root1==NULL)
    {
        root1=getnode(dat);
    }
    else 
    {
        if (dat<(root1->data))
        root1->left=insert(root1->left,dat);
        else 
        root1->right=insert(root1->right,dat);
    }
    return root1;
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

bool AVL(Node* root)
{
    if (root!=NULL)
    {
        int l=height(root->left);
        int r=height(root->right);
        if (l-r==0 || l-r==1 || l-r==-1)
        {
            if (AVL(root->left) && AVL(root->right))
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

int main()
{
    Node* root=NULL;
    root=insert(root,23);
    insert(root,34);
    insert(root,19);
    insert(root,20);
    insert(root,18);
    if (AVL(root))
    cout<<"Is AVL tree."<<endl;
    else
    cout<<"Not a AVL tree.";
}