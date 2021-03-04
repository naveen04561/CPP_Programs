#include<iostream>
using namespace std;
class stack1
{
    private:
    int top;
    int arr[20];
    public:
    stack1()
    {
        top=-1;
    }
    int size();
    bool isempty()
    {
        if (top==-1)
        return true;
        else 
        return false;
    }
    bool isfull()
    {
        if (top==19)
        return true;
        else 
        return false;
    }
    void push(int val)
    {
        if (isfull())
        cout<<"Stack overflow ";
        else
        {
            top++;
            arr[top]=val;
        }
    }
    int pop()
    {
        if (isempty())
        {
             cout<<"Stack underflow ";
             return 0;
        }
        else
        return (arr[top--]);
    }
    void display()
    {
    	for (int i=0;i<=top;i++)
    	{
    		cout<<arr[i]<<"\t";
    	}
    }

};

int stack1::size()
{
    return top;
}


int main() 
{
    stack1 s1,s2;
    int i,n,h,a;
    while(1)
    {
        cout<<endl<<"Enter the option number "<<endl;
        cout<<"1.Add elements to the queue "<<endl<<"2.Delete element from queue "<<endl<<"3.Display the elements of the queue: "<<endl<<"4.Exit"<<endl;
        cin>>h;
        switch (h)
        {
            case 1:
            cout<<"Enter the no.of elements ";
            cin>>n;
            for (i=0;i<n;i++)
            {
            	cin>>a;
            	s1.push(a);
            }
            break; 
            case 2:
            cout<<"Enter the number of elements to be deleted ";
            cin>>n;
            while(!(s1.isempty()))
            s2.push(s1.pop());
            for (i=0;i<n;i++)
            {  
            	s2.pop();
            }
            while(!(s2.isempty()))
            s1.push(s2.pop());
            break; 
            case 3:
       	    /*if (s2.isempty())
                s1.display();
            else 
                s2.display();*/
            s1.display();
             break; 
             case 4:
             exit(0);
             break;
		}
    }
}

    
    
    
    
    
    
    
    
  
    
    
    
    
    
    
    
   