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
Node* getnode(int da)
{
    Node* n;
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
            return root1;
        }
        else if(dat>=(root1->data))
        {
            root1=(searchnode(root1->right,dat));
            return root1;
        }
        else
        {
            return NULL;
        }
        
    }
}


int main()
{
    int t,n,i,j;
    cin>>t;
    while(t>0)
    {
        cin>>n;
        int a[n],sum = 0,triplets=0;
        Node* root = NULL;
        cin>>a[0];
        root = insert(root,a[i]);
        for(i=1;i<n;i++)
        {
            cin>>a[i];
            insert(root,a[i]);
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                sum = a[i] + a[j];
                if(searchnode(root,sum)!=NULL)
                triplets++;
            }
        }
        if(triplets!=0)
            cout<<triplets<<endl;
        else
            cout<<"-1"<<endl;
        t--;
    }   
}