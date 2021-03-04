#include<bits/stdc++.h>
using namespace std;

class Node
{
	public:
		char data;
		Node* left;
		Node* right;
		Node()
		{
			data=0;
			left=NULL;
			right=NULL;
		}
};



	
Node* getnode(char dat)
{
	Node* n=new Node;
	n->data=dat;
	n->left=NULL;
	n->right=NULL;
	return n;
}
void preorder(Node* root1)
{
	if (root1!=NULL)
	{
		cout<<root1->data;
		preorder(root1->left);
		preorder(root1->right);	
	}	
}

void inorder(Node* root1)
{
	if (root1!=NULL)
	{
		inorder(root1->left);
		cout<<root1->data;
		inorder(root1->right);
	}	
}

void postorder(Node* root)
{
	if (root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout<<root->data;
	}
}

string infixpost(string s1){
	stack< char > s;
	string s2;
	int i,n;
	char c;
	s.push('(');
	for (i=0;i<s1.length();i++)
	{
		if (s1[i]>='a'&&s1[i]<='z')
		{
			s2+=s1[i];
		}
		else if (s1[i]=='(')
		{
			s.push(s1[i]);
		}
		else if (s1[i]=='+'||s1[i]=='-'||s1[i]=='*'||s1[i]=='/')
		{
			switch(s.top())
			{
				case '+':
				if (s1[i]=='+'||s1[i]=='-')
					{
						while(s.top()!='(')
						{	
							c=s.top();
							s.pop();
							s2+=c;
						}
						s.push(s1[i]);
					}
				else if (s1[i]=='*'||s1[i]=='/')
					{
						s.push(s1[i]);
					}
				break;
				case '-':
				s.push(s1[i]);
				break;
				case'*':
				if (s1[i]=='+'||s1[i]=='-'||s1[i]=='*')
				{
					while(s.top()!='(')
						{	
							c=s.top();
							s.pop();
							s2+=c;
						}
						s.push(s1[i]);
				}
				else if (s1[i]=='/')
				{
						s.push(s1[i]);
				}
				break;
				case'/':
				if (s1[i]=='+'||s1[i]=='-'||s1[i]=='*')
					{
						while(s.top()!='(')
						{	
							c=s.top();
							s.pop();
							s2+=c;
						}
						s.push(s1[i]);
					}
				break;
				
				default:
				s.push(s1[i]);
				break;
				
			}
			}
			else if (s1[i]==')')
			{
				while(s.top()!='(')
						{	
							c=s.top();
							s.pop();
							s2+=c;
						}
					s.pop();
			}
			}
			
			while(!s.empty())
			{
				if (s.top()=='(')
				{
					s.pop();
					break;
				}
				else
				{
					c=s.top();
					s.pop();
					s2+=c;
				}
			}
			return s2;
}

int main()
{
	Node*root=NULL;
	string s;
	stack< Node*> st;
	cout<<"Enter the expression ";
	cin>>s;
	string s1=infixpost(s);
	for (int i=0;i<s1.length();i++)
	{
		if (s1[i]>='a'&&s1[i]<='z')
		{
			st.push(getnode(s1[i]));
		}
		else if(s1[i]=='+' || s1[i]=='-' || s1[i]=='*' ||s1[i]=='/')
		{
				root=getnode(s1[i]);
				root->right=st.top();
				st.pop();
				root->left=st.top();
				st.pop();
				st.push(root);
		}
	}
	preorder(root);
	cout<<endl;
	inorder(root);
	cout<<endl;
	postorder(root);
}
















