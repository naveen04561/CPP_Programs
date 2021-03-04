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

bool compareBT(Node* root1,Node* root2)
{
    if(root1 == NULL && root2 == NULL)
        return true;
    else if(root1 == NULL && root2!= NULL || root1!= NULL && root2 == NULL)
        return false;
    else
    {
        if(root1->data == root2->data)
        {
            if(compareBT(root1->left,root2->left))
            {
                if(compareBT(root1->right,root2->right))
                    return true;
                else 
                    return false;
            }
            else
                return false;
        }
        else 
            return false;
    }
    
}

int main()
{
    Node* root1;
    Node* root2;
    cout<<root1<<root2<<endl;
    root1->data = 1,root2->data = 2;
    cout<<compareBT(root1,root2);
    delete root1;
    delete root2;
    return 0;
}