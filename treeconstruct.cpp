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
Node* root=NULL;
Node* getnode(int data)
{
    Node* n=new Node;
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}

void construct(int pre[],int in[],int n,Node* root1)
{
    if (n==3)
    {
        root1->left=getnode(in[0]);
        root1->right=getnode(in[2]);
        return;
    }
    else if (n==2)
    {
        root1->left=getnode(in[0]);
        return;
    }
     if (n==1)
    {
        return;
    }
    else{
        int pos;
        for(int i=0;i<n;i++)
        {
            if(in[i]==pre[0])
            {
                pos=i;
                break;
            }
        }
        int l[pos],r[n-pos-1],lpr[pos],rpr[n-pos-1];
        for (int i=0;i<pos;i++)
        {
            lpr[i]=pre[i+1];
            l[i]=in[i];
        }
        root1->left=getnode(lpr[0]);
        construct(lpr,l,pos,root1->left);
        for (int j=0;j<n-pos-1;j++)
        {
            rpr[j]=pre[j+pos+1];
            r[j]=in[pos+j+1];
        }
        root1->right=getnode(rpr[0]);
        construct(rpr,r,pos,root1->right);
        return;
    }
}
void postorder(Node* root1)
{
    if (root1==NULL)
    return;
    else
    {
        postorder(root1->left);
        postorder(root1->right);
        cout<<root1->data<<endl;
    }
}

int main()
{
    int pre[]={1,2,4,5,3,6},in[]={4,2,5,1,6,3};
    root=getnode(pre[0]);
    int n = sizeof(in)/sizeof(in[0]);
    construct(pre,in,n,root);
    postorder(root);
}