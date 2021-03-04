#include<iostream>
using namespace std;


class Node
{
	public:
	int data;
	Node* prev;
	Node* next;
	
	Node ()
	{
		data=0;
		prev=NULL;
		next=NULL;
	}
};

class Doublyll
{
	public:
	Node* head;
	Doublyll()
	{
		head=NULL;
	}
	Node* getnode(int d)
	{
		Node* n=new Node;
		n->data=d;
		return n;
	}
	void insert(int dat)
	{
		Node*n=getnode(dat);
		Node* temp=head;
		if (head==NULL)
		{
			head=n;
			cout<<"Node appended"<<endl;
		}
		else
		{
			if (head->next==NULL)
			{
				head->next=n;
				n->prev=head;
				cout<<"Node appended"<<endl;
			}
			
			else if (head->next!=NULL)
			{
				while(temp->next!=NULL)
				{
					temp=temp->next;
				}
				n->prev=temp;
				temp->next=n;
				cout<<"Node appended"<<endl;
			}
		}
	}
	void deletenode(int dat)
	{
		Node* temp=head;
		Node* p;
		if (head==NULL)
		cout<<"No node present"<<endl;
		else if (head->next==NULL&&head->data!=dat)
		{
			cout<<"No node with given data"<<endl;
		}
		else 
		{
			if (head->next==NULL&&head->data==dat)
			{
				cout<<"Data is "<<head->data<<endl;
				delete head;
				cout<<"Node deleted"<<endl;
				head=NULL;
			}
			else if (head->next!=NULL&&head->data==dat)
			{
				p=head->next;
				delete head;
				head=p;
				cout<<"Node deleted"<<endl;
			}
			else if (temp->next!=NULL)
			{
				while(temp->next!=NULL&&temp->data!=dat)
				{
					p=temp;
					temp=temp->next;
				}
				if (temp->next==NULL&&temp->data!=dat)
				{
					cout<<"No node with given data"<<endl;
				}
				else if (temp->next==NULL&&temp->data==dat)
				{
					cout<<"node deleted"<<endl;
					p->next=NULL;
					delete temp;
					temp=head;
				}
				else 
				{
					cout<<"Node deleted"<<endl;
					p->next=temp->next;
					temp->next->prev=p;
					delete temp;
				}
			}
		}
	}
	
	
	void display()
	{
		Node* temp=head;
		if (head==NULL)
		{
			cout<<"No node present"<<endl;
		}
		else
		{
			while(temp!=NULL)
			{
				cout<<temp->data<<endl;
				temp=temp->next;
			}
		}
	}
};


int main()
{
	Doublyll d;
	int op,n,a,b;
	while(1)
	{
		cout<<"Enter the option number :"<<endl<<"1.Add an element "<<endl<<"2.Delete an element "<<endl<<"3.Display all the elements "<<endl<<"4.Exit"<<endl;
		cin>>op;
		if(op==4)
		break;
		switch(op)
		{
			case 1:
				cout<<"Enter the data ";
				cin>>a;
				d.insert(a);
			break;
			
			case 2:
				cout<<"Enter the data of element to be deleted :";
				cin>>b;
				d.deletenode(b);
			break;
			
			case 3:
				d.display();
			break;
			
		}
	}
}


































