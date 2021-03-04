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
	stack1 s;
	int i, n;
	char c;
	string s1, s2;
	cout << "Enter the infix expression ";
	cin >> s1;
	s.push('(');
	for (i = 0; i < s1.length(); i++)
	{
		if (s1[i]>='a'&&s1[i]<='z')
		{
			s2 += s1[i];
			continue;
		}
		else if (s1[i] == '(')
		{
			s.push(s1[i]);
			continue;
		}
		else if (s1[i] == '+' || s1[i] == '-' || s1[i] == '*' || s1[i] == '/')
		{
			switch (s.peek())
			{
			case '+':
				if (s1[i] == '+'||s1[i]=='-')
				{
					while ((s.peek()) != '(')
					{
						c = s.pop();
						s2 += c;
					}
					s.push(s1[i]);
				}
				else if (s1[i] == '*'||s1[i]=='/')
				{
					s.push(s1[i]);
				}
				break;

			case '-':
				s.push(s1[i]);
				break;

			case '*':
				if (s1[i] == '+'||s1[i]=='-'||s1[i]=='*')
				{
					while ((s.peek()) != '(')
					{
						c = s.pop();
						s2 += c;
					}
					s.push(s1[i]);
				}
				else if (s1[i] == '/')
				{
					s.push(s1[i]);
				}
				break;

			case '/':
				if (s1[i] == '+' || s1[i] == '-' || s1[i] == '*' || s1[i] == '/')
				{
					c = s.pop();
					s2 += c;
					s.push(s1[i]);
				}
				break;

			default:
				s.push(s1[i]);
				break;
			}
		}
		else if (s1[i] == ')')
		{
			while (s.peek() != '(')
			{
				c = s.pop();
				s2 += c;
			}
			s.pop();
		}
	}
	while (!(s.isempty()))
	{
		if (s.peek() == '(')
		{
			s.pop();
			break;
		}
		else
		{
			c = s.pop();
			s2 += c;
		}
	}
	cout <<"The postfix expression is "<< s2;
	return 0;
}