#include<bits/stdc++.h>
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
    bool isempty();
    bool isfull();
    void enqueue(int);
    int dequeue();
    void display();
    int pop();
};
Queue q1,q2;
    bool Queue:: isempty()
    {
        if((front==-1&&rear==-1))
            return true;
        else
            return false;
    }
    bool Queue:: isfull()
    {
        if (rear>front)
        return true;
        else 
        return false;
    }
    void Queue:: enqueue(int val)
    {
        if (isempty())
        {
            front=0;
            rear=0;
            arr[rear]=val;
        }
        else
        {
            rear++;
            arr[rear]=val;
        }
    }
    int Queue::dequeue()
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
            front++;
            return x;
        }
    }
    int Queue::pop()
    {
    	for (int i=q1.front;i<=q1.rear-1;i++)
    	{
    		q2.enqueue(q1.dequeue());
    	}
        if (!q1.isempty())
    	q1.dequeue();
        else 
        {
            q2.dequeue();
            return 0;
        }
    	for (int i=q2.front;i<=q2.rear;i++)
    	{
		q1.enqueue(q2.dequeue());
    	}
        return 0;
    }
    void Queue:: display()
    {
    	if (q1.isempty()){
    	cout<<"No elements present"<<endl;
    	}
    	else{
    	 cout<<"The elements are "<<endl;
       for (int i=q1.front;i<=q1.rear;i++)
       cout<<q1.arr[i]<<'\t';
       cout<<endl;
       }
    }

int main()
{
	int i,op,n,d;
	while(1)
	{
		cout<<"Enter the option number "<<endl;
		cout<<"1.Add elements "<<endl<<"2.Pop elements "<<endl<<"3.Display all the elements "<<endl<<"4.Exit"<<endl;
		cin>>op;
		if (op==4)
		break;
		switch(op)
		{
			case 1:
				cout<<"Enter the number of elements to be pushed "<<endl;
				cin>>n;
				cout<<"enter the elements "<<endl;
				for (i=0;i<n;i++)
				{
					cin>>d;
					q1.enqueue(d);
				}
			break;
			case 2:
				if (!q1.isempty())
				q1.pop();
				else
				cout<<"No elements present"<<endl;
			break;
			case 3:
				q1.display();
			break;
		}
	}
}
