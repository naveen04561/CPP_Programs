#include<iostream>
#include<string>
using namespace std;
class stack1
{
    private:
    int top;
    string arr[20];
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
    void push(string val)
    {
        if (isfull())
        cout<<"Stack overflow ";
        else
        {
            top++;
            arr[top]=val;
        }
    }
    string pop()
    {
        if (isempty())
        {
             cout<<"Stack underflow ";
             return 0;
        }
        else
        return (arr[top--]);
    }
    string peek ()
    {
        return (arr[top]);
    }
};

int main()
{
    stack1 s1 ;
    string s,s3;
    string op1,op2,op;
    int i,n;
    cout<<"Enter the postfix expression :";
    cin>>s;
    for(i=0;i<s.length();i++)
    {
        if (s[i]>='a'&&s[i]<='z')
        {
            string c;
            c+=s[i];
            s1.push(c);
            continue;
        }
        else if (s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/')
        {
            op1=s1.pop();
            op2=s1.pop(); 
            op=s[i];
            string s3;
            s3+='{';
            s3+=op2;
            s3+=op;
            s3+=op1;
            s3+='}';
            s1.push(s3);
        }
    }
    while(!s1.isempty())
    {
        s3+=s1.pop();
    }
    cout<<s3;
}