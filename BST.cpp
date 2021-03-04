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

int numbernodes(Node* root1)
{
    if (root1==NULL)
    return 0;
    else 
    return (numbernodes(root1->left)+numbernodes(root1->right)+1);
}

Node* searchnode(Node* root1,int dat)
{
    if (root1==NULL)
    return root1;
    else if (root1->data==dat)
    return root1;
    else
    {
        if (dat<(root1->data))
        {
            root1=(searchnode(root1->left,dat));
        }
        else if(dat>=(root1->data))
        {
            root1=(searchnode(root1->right,dat));
        }
        return root1;
    }
}

int insuccessor(Node* root1,int data)
{
    if (root1==NULL)
    return 0;
    else
    {
        Node* n=searchnode(root1,data);
        if(n->right!=NULL)
        {
            Node*temp = n->left;
            while(temp!=NULL)
                temp=temp->left;
            return temp->data;
        }
        else
        {
            
        }
    }
}

int main()
{
    int op,n,i,d;
    Node* root=NULL;
    while(1)
    {
        cout<<"Enter the option number "<<endl<<"1.Add a node "<<endl<<"2.Inorder successor"<<endl<<"3.Search an element "<<endl<<"4.Exit"<<endl;
        cin>>op;
        if(op==4)
        break;
        switch(op)
        {
            case 1:
                cout<<"Enter the data ";
                cin>>d;
                if (root==NULL)
                root=insert(root,d);
                else 
                insert(root,d);
            break;
            case 2:
                cout<<"Enter the value whose inorder successor to be found :"<<endl;
                cin>>d;
                cout<<insuccessor(root,d)<<endl;
            break;
            case 3:
                cout<<"Enter the data ";
                cin>>d;
                Node* n=searchnode(root,d);
                cout<<n->data<<endl;
            break;
        }
    }
}