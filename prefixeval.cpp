#include <iostream>
#include <string>
using namespace std;
class stack1
{
  private:
	int top;
	char arr[20];

  public:
	stack1()
	{
		top = -1;
	}
	int size();
	bool isempty()
	{
		if (top == -1)
			return true;
		else
			return false;
	}
	bool isfull()
	{
        if (top == 19)
			return true;
		else
			return false;
	}
	void push(char val)
	{
		if (isfull())
			cout << "Stack overflow ";
		else
		{
			top++;
			arr[top] = val;
		}
	}
	char pop()
	{
		if (isempty())
		{
			cout << "Stack underflow ";
			return 0;
		}
		else
		{
			return (arr[top--]);
		}
	}
    char peek()
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
	stack1 s1,s2;
	string s;
	int i,op1,op2,result;
	char op;
	cout << "Enter the prefix expression ";
	cin >> s;
	for (i=0;i<s.length();i++)
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
	int y=s1.pop();
	cout<<"The result is :"<<y;
}