#include<iostream>
#include<string>
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
        for (int i=0;i<20;i++)
        arr[i]=0;
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
    int peek ()
    {
        return (arr[top--]);
    }

};

int stack1::size()
{
    return top;
}


int main() 
{
    stack1 s1;
    int i,n,result=0,y;
    string s;
    char op;
    int op1,op2;
    cout<<"Enter the string ";
    cin>>s;
    for(i=0;i<s.length();i++)
    {
        if (s[i]!='+'&&s[i]!='-'&&s[i]!='*'&&s[i]!='/')
        {
            s1.push(s[i]-48);
        }
        else if (s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
        {
             op=s[i];
             op1= s1.pop();
             op2= s1.pop();
            if (op=='+')
              { result=op1+op2;
               s1.push(result);
              }
            else if(op=='-')
               {result=(op1-op2);
               s1.push(result);
               }
            else if (op=='*')
               {result=(op1)*(op2);
                s1.push(result);
               }
            else if (op=='/')
              { result=(op1)/(op2);
               s1.push(result);
              }
        }
    }
    y=s1.pop();
    cout<<"result is "<<y;
}