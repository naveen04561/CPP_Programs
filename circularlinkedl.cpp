#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    int key;
    Node *next;

    Node()
    {
        data=0;
        key=0;
        next=NULL;
    }
    Node(int d)
    {
        data=d;
    }
};

class circularlinked
{
    public:
    Node* head;
    circularlinked()
    {
        head=NULL;
    }
    Node* getnode(int dat)
    {
        Node* n=new Node();
        n->data=dat;
        return n;
    }
    void appendnode(int dat)
    {
        Node* temp=head;
        Node*n=getnode(dat);
        if (head==NULL)
        {
            head=n;
            n->next=n;
            cout<<"Node appended "<<endl;
        }
        else 
        {
            if(head->next==head)
            {
                head->next=n;
                n->next=head;
                cout<<"Node appended "<<endl;
            }
            else 
            {
                Node* temp=head;
                while(temp->next!=head)
                {
                    temp=temp->next;
                }
                temp->next=n;
                n->next=head;
                cout<<"Node appended"<<endl;
            }
        }
    }
    void deletenode(int num)
    {
        while(1){
        Node* curr=head;
        Node* p=NULL;
        Node* prev=NULL;
        if (head->next==head)
        break;
        if (num==1)
        {
            p=curr;
            curr=curr->next;
            cout<<p->data<<endl;
            delete p;
            Node* temp=head;
            while(temp->next!=head)
            temp=temp->next;
            temp->next=curr;
            head=curr;
        }
        else
        {
            for (int i=1;i<num;i++)
            {
                prev=curr;
                curr=curr->next;
            }
            prev->next=curr->next;
            cout<<curr->data<<endl;
            delete curr;
        }
    }
    }
    void display()
    {
        Node* temp=head;
        while(temp->next!=head)
        {
            cout<<temp->data<<'\t';
            temp=temp->next;
        }
        cout<<temp->data<<endl;
    }
};


int main()
{
    circularlinked c;
    int option,data1;
    while(1)
    {
        cout<<"Enter the option number "<<endl;
        cout<<"1.Append a node "<<endl<<"2.Display the nodes "<<endl<<"3.Delete a node "<<endl<<"4.Exit"<<endl;
        cin>>option;   
        switch(option)
        {
            case 1:
                cout<<"Enter the data ";
                cin>>data1;
                c.appendnode(data1);
            break;
            case 3:
                cout<<"Enter the number the of node to be deleted ";
                cin>>data1;
                c.deletenode(data1);
                break;
            
            case 2:
                c.display();
            break;

            case 4:
                exit(0);
            break;
        }
    }
}

