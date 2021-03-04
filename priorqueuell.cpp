#include<iostream>
using namespace std;

class Node
{
	public:
	int data,key;
	Node* next;
	Node()
	{
		next=NULL;
		data=0;
		key=0;
	}
	Node(int d,int k)
	{
		d=data;
		k=key;
	}	
};

class Queue
{
	public:
	Node* front;
	Node* rear;
	Queue()
	{
		front=NULL;
		rear=NULL;
	}
	bool isempty()
	{
		if(front==NULL&&rear==NULL)
		return true;
		else
		return false;
	}
	void getnode(Node* n,int d, int k)
	{
		n->data=d;
		n->key=k;
	}
	void Enqueue(Node* n,int d,int k)
	{
		getnode(n,d,k);
		Node* temp=front;
		if(isempty())
		{
			front=n;
			rear=n;
		}
		
		else
		{
			if(front==rear&&k<=front->key)
			{
					temp=n;
					temp->next=front;
					front=temp;
			}
			else if (front!=rear&&k<=front->key)
			{
					temp=n;
					temp->next=front;
					front=temp;
			}
			else
				{
					while(temp->next!=NULL&&temp->key<k)
					{
						temp=temp->next;
					}
					temp->next=n;
					rear=n;
				}
			}
		}
	
	void Dequeue()
	{
		Node* temp;
		if (isempty())
		{
			cout<<"No node present"<<endl;
		}
		else
		{
			temp=front;
			front=front->next;
			rear=NULL;
			delete temp;
		}
	}
	void display()
	{
		Node* temp=front;
		if (isempty())
		{
			cout<<"No node present"<<endl;
		}
		else
		{
			while(temp!=NULL)
			{
				cout<<temp->data<<"\t"<<temp->key<<endl;
				temp=temp->next;
			}
		}
	}
};

int main()
{
	Queue q;
	int op,n,a,b;
	while(1)
	{
		cout<<"Enter the option number :"<<endl<<"1.Add an element "<<endl<<"2.Delete an element "<<endl<<"3.Display all the elements "<<endl<<"4.Exit"<<endl;
		cin>>op;
		if(op==4)
		break;
		Node* n=new Node();
		switch(op)
		{
			case 1:
				cout<<"Enter the data and key: ";
				cin>>a>>b;
				q.Enqueue(n,a,b);
			break;
			
			case 2:
				q.Dequeue();
			break;
			
			case 3:
				q.display();
			break;
			
		}
	}
}













































