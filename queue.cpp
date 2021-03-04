#include<iostream>
using namespace std;

class Queue
{
    private:
    int front,rear,arr[20];
    public:
    Queue()
    {
        front=-1;
        rear=-1;
    }
    bool isempty()
    {
        if((front==-1&&rear==-1)||rear<front)
            return true;
        else
            return false;
    }
    bool isfull()
    {
        if (rear==19)
            return true;
        else 
            return false;
    }
    void enqueue(int val)
    {
        if (isfull())
            cout<<"Queue is full ";

        else if (front==-1)
        {
            front++;
            rear++;
            arr[rear]=val;
        }
        else
        {
            rear++;
            arr[rear]=val;
        }
    }
    int dequeue()
    {
        if (isempty())
        {
            cout<<"Queue is empty ";
            return 0;
        }
        else 
            return arr[front++];
    }
    int peek()
    {
        return arr[front];
    }
    void display()
    {
        for (int i=front;i<=rear;i++)
        {
            cout<<arr[i]<<'\t';
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
        cout<<"1.Add element to the queue "<<endl<<"2.Delete element from queue "<<endl<<"3.Display the elements of the queue: "<<endl<<"4.Exit"<<endl;
        cin>>h;
        switch (h)
        {
            case 1:
            cout<<"Enter the number of values: ";
            cin>>n;
            for (i=0;i<n;i++)
            {
                cin>>a;
                q.enqueue(a);
            }
            break;
            case 2:
            cout<<"Enter the number of values to be deleted: ";
            cin>>n;
            for (i=0;i<n;i++)
            {
                q.dequeue();
            }
            break;
            case 3:
            cout<<"The values are: "<<endl;
            q.display();
            break;
            case 4:
            exit(0);
            break;
        }
    }
}