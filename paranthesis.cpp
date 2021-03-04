#include<iostream>
#include<string>
using namespace std;
class stack1
{
    private:
    int top;
    char arr[20];
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
    void push(char val)
    {
        if (isfull())
        cout<<"Stack overflow ";
        else
        {
            top++;
            arr[top]=val;
        }
    }
    char pop()
    {
        if (isempty())
        {
             cout<<"Stack underflow ";
             return 0;
        }
        else
        return (arr[top--]);
    }
    char peek ()
    {
        return (arr[top]);
    }

};

int stack1::size()
{
    return top;
}


int main() 
{
    stack1 s1;
    int i,n,c,flag=0;
    string s;
    char s2;
    cout<<"Enter the brackets ";
    cin>>s;
    for (i=0;i<s.length();i++)
    {
        if (s[i]=='{'||s[i]=='('||s[i]=='[')
        {
            s1.push(s[i]);
            continue;
        }
        
           if (s1.isempty())
          {
            flag=1;
            break;
          }
          else
            {
                switch(s1.peek())
                {
                    case '(':
                    s2=s[i];
                    if (s2=='}'||s2==']')
                    {
                        flag=1;
                        break;
                    }
                    else
                    s1.pop();
                    break;
                    case '{':
                    s2=s[i];
                    if (s2==')'||s2==']')
                    {
                        flag=1;
                        break;
                    }
                    else
                    s1.pop();
                    break;
                    case '[':
                    s2=s1.pop();
                    if (s2==')'||s2=='}')
                    {
                        flag=1;
                        break;
                    }
                    else
                    s1.pop();
                    break;

                }
            
        }             
            
        }
        if (flag==0&&(s1.isempty()))
        cout<<" balanced ";
        else
        {
            cout<<"String not balanced ";
        }
        
    
}