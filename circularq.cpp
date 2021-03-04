#include<iostream>
using namespace std;

class Queue
{
    private:
    int front,rear,arr[5];
    public:
    Queue()
    {
        front=-1;
        rear=-1;
        for (int i=0;i<5;i++)
        arr[i]=0;
    }
    bool isempty()
    {
        if((front==-1&&rear==-1))
            return true;
        else
            return false;
    }
    bool isfull()
    {
        if ((rear+1)%5==front)
        return true;
        else 
        return false;
    }
    void enqueue(int val)
    {
        if (isempty())
        {
            front=0;
            rear=0;
            arr[rear]=val;
        }
        else
        {
            rear=(rear+1)%5;
            arr[rear]=val;
        }
    }
    int dequeue()
    {
        if (front==rear)
        {
            int x=arr[front];
            front=-1;
            rear=-1;
            return x;
        }
        else 
        {
            int x=arr[front];
            arr[front]=0;
            front=(front+1)%5;
            return x;
        }
    }
    void display()
    {
        if (rear>=front)
        {
            for (int i=front;i<=rear;i++)
            cout<<arr[i]<<"\t";
        }
        else {
            for (int i=front;i<5;i++)
            cout<<arr[i]<<"\t";
            for (int i=0;i<=rear;i++)
            cout<<arr[i]<<"\t";
        }
    }
};

int main()
{
    Queue q;
    int i,n,h,a;
    while(1)
    {
        cout<<endl<<"Enter the option number "<<endl;
        cout<<"1.Add elements to the queue "<<endl<<"2.Delete element from queue "<<endl<<"3.Display the elements of the queue: "<<endl<<"4.Exit"<<endl;
        cin>>h;
        switch (h)
        {
            case 1:
            if (q.isfull())
            cout<<"Queue is full"<<endl;
            else{
            cout<<"Enter the number of values: ";
            cin>>n;
            for (i=0;i<n;i++)
            {
                cin>>a;
                q.enqueue(a);
            }
            }
            break;
            case 2:
            if (q.isempty())
            {
            cout<<"Queue is empty ";
            }
            else{
            cout<<"Enter the number of values to be deleted: ";
            cin>>n;
            for (i=0;i<n;i++)
            {
                q.dequeue();
            }
            }
            break;
            case 3:
            if (q.isempty())
            cout<<"Queue is empty"<<endl;
            else{
            cout<<"The values are: "<<endl;
            q.display();
            }
            break;
            case 4:
            exit(0);
            break;
        }
    }
}