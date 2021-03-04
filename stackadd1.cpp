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

};

int stack1::size()
{
    return top;
}


int main() 
{
    stack1 s1,s2;
    int a[20],i,j,n,n1,n2,c,carry=0,sum=0;
    cout<<"Enter the number of digits in the larger number :";
    cin>>n1;
    cout<<"Enter the digits :";
    for (i=0;i<n1;i++)
    {
        cin>>c;
        s1.push(c);
    }
    cout<<"Enter the number of digits in the second number :";
    cin>>n2;
    cout<<"Enter the digits :";
    for (i=0;i<n2;i++)
    {
        cin>>c;
        s2.push(c);
    }
    n=n1;
    for (i=0;i<n1;i++)
        {
            if (s2.isempty())
            for (j=0;j<(n1-n2);j++)
            s2.push(0);
            sum=s1.pop()+s2.pop()+carry;
            if (i==n1-1&&sum>=10)
            {
              a[i]=sum;
              break;
            }
            a[i]=sum%10;
            carry=sum/10;
        }
    cout<<"Sum is :";
    for (i=n-1;i>=0;i--)
    cout<<a[i];
}