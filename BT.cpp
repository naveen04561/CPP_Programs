#include<bits/stdc++.h>
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

queue <Node* >q;
Node* root=NULL;
Node* getnode(int data)
{
    Node* n=new Node;
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}
void insert(int data)
{
    if (root==NULL)
    {
        root=getnode(data);
        q.push(root);
        return;
    }
    else
    {
        Node*n=q.front();
        if (n->left==NULL&&n->right==NULL)
        {
            n->left=getnode(data);
            q.push(n->left);
        }
        else if (n->left!=NULL&&n->right==NULL)
        {
            n->right=getnode(data);
            q.push(n->right);
        }
        else
        {
            q.pop();
            insert(data);
        }
        return;
    }
}

void preorder(Node* root1)
{
    if (root1==NULL)
    return;
    else
    {
        cout<<root1->data<<endl;
        preorder(root1->left);
        preorder(root1->right);
    }
}

void inorder(Node* root1)
{
    if (root1==NULL)
    return;
    else
    {
        inorder(root1->left);
        cout<<root1->data<<endl;
        inorder(root1->right);
    }
}


int insuccessor(Node* root,int data)
{
    if (root==NULL)
    return 0;
    else
    {
        
    }   
}

int main()
{
    int op,n,i,d;
    while(1)
    {
        cout<<"Enter the option number "<<endl<<"1.Add a node "<<endl<<"2.Inorder successor"<<endl<<"3.Exit"<<endl;
        cin>>op;
        switch(op)
        {
            case 1:
                cout<<"Enter the data ";
                cin>>d;
                insert(d);
            break;
            case 2:
                cout<<"Enter the value whose inorder successor to be found :"<<endl;
                cin>>d;
                cout<<insuccessor(root,d)<<endl;
            break;
            case 3:
                inorder(root);
                exit(0);
            break;
        }
    }
}
