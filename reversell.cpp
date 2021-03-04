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
    int reverse()
    {
        Node* temp=head;
        Node*p=head->next;
        Node* ptr;
        if (head->next==NULL || head == NULL)
        return 0;
        else
        {
            while(p->next!=NULL)
            {
                ptr=p->next;
                p->next=temp;
                temp=p;
                p=ptr;
            }
            head->next=NULL;
            p->next=temp;
            head=p;
            return 0;
        }
    }
};

int main()
{
    singlylinked s;
    int option,data1,n,i;
    while(1)
    {
        cout<<"Enter the option number "<<endl;
        cout<<"1.Append nodes "<<endl<<"2.Display the nodes "<<endl<<"3.Reverse the list"<<endl<<"4.Exit"<<endl;
        cin>>option;   
        switch(option)
        {
            case 1:
                cout<<"enter the number of nodes ";
                cin>>n;
                for (i=0;i<n;i++)
                {
                    cout<<"Enter the data ";
                    cin>>data1;
                    s.appendnode(data1);
                }
            break;
            case 2:
                s.display();
                break;
            break;

            case 3:
               s.reverse();
            break;

            case 4:
                exit(0);
            break;
        }
    }
}