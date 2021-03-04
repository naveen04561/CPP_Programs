#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;

    Node()
    {
        data=0;
        next=NULL;
    }
    Node(int d)
    {
        data=d;
    }
};

class singlylinked
{
    public:
    Node* head;
    singlylinked()
    {
        head=NULL;
    }
    Node* getnode(int dat)
    {
        Node* n=new Node();
        n->data=dat;
        return n;
    }
    void appendnode(int a)
    {
        Node*n1=getnode(a);
        if (head==NULL)
        {
            head=n1;
            cout<<"Node appended"<<endl;
        }
        else 
        {
            if (head->next==NULL)
            {
                head->next=n1;
                cout<<"Node appended"<<endl;
            }
            else 
            {
                Node* temp;
                temp=head;
                while(temp->next!=NULL)
                {
                    temp=temp->next;
                }
                temp->next=n1;
                temp==NULL;
                cout<<"Node appended"<<endl;
            }
        }
    }
    void prependnode(int dat)
    {
        Node* n=getnode(dat);
        Node *temp=head;
        head=n;
        head->next=temp;
        temp==NULL;
        cout<<"Node prepended "<<endl;
    }
    void deletenode(int d)
    {
        Node* temp=head;
        Node* ptr;
        if (head==NULL)
        {
            cout<<"No node present "<<endl;
        }
        else if (head->next==NULL&&head->data!=d)
            {
                cout<<"No node with the given data ";
            }
        else if (head->next==NULL&&head->data==d)
            {
                delete temp;
                cout<<"Node deleted "<<endl;
            }
        else if (head->next!=NULL&&head->data==d)
            {
                head=head->next;
                temp->next=NULL;
                delete temp;
                cout<<"Node deleted "<<endl;
            }
        else
        {
            while(temp!=NULL&&temp->data!=d)
            {
                ptr=temp;
                temp=temp->next;
            }
            if (temp==NULL&&ptr->data!=d)
            {
                cout<<" No Node with given data "<<endl;
            }
            else if (temp!=NULL)
            {
                ptr->next=temp->next;
                delete temp;
                cout<<"Node deleted "<<endl;
            }
        }
        
    }
    void display()
    {
        Node* temp=head;
        int a=1;
        if (temp==NULL)
        {
            cout<<"No node present ";
        }
        else
        {
            while(temp!=NULL)
            {
                cout<<"Data at node "<<a<<"="<<(temp->data)<<endl;
                temp=temp->next;
                a++;
            }
        }
    }
    void delduplicates()
    {
        Node* temp=head;
        if (head==NULL)
        return;
        else
        {
            if (head->next==NULL)
            return;
            else
            {
                Node* p;
                while(temp->next!=NULL)
                {
                    if (temp->data==temp->next->data)
                    {
                        p=temp->next;
                        temp->next=p->next;
                        temp=temp->next;
                        delete p;
                    }
                }
            }
            
        }
    }
};

int main()
{
    singlylinked s;
    int option,data1;
    while(1)
    {
        cout<<"Enter the option number "<<endl;
        cout<<"1.Append a node "<<endl<<"2.Prepend a node "<<endl<<"3.Display the nodes "<<endl<<"4.Delete a node "<<endl<<"5.Exit"<<endl;
        cin>>option;   
        switch(option)
        {
            case 1:
                cout<<"Enter the data ";
                cin>>data1;
                s.appendnode(data1);
            break;

            case 2:        
                cout<<"Enter the data :";
                cin>>data1;
                s.prependnode(data1);
            break;

            case 3:
                s.display();
                break;
            break;

            case 4:
                cout<<"Enter the data of the node to be deleted ";
                cin>>data1;
                s.deletenode(data1);
                s.delduplicates();
            break;

            case 5:
                exit(0);
            break;
        }
    }
}