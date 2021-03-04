#include<bits/stdc++.h>
using namespace std;

class Node
{
	public:
		int data;
		Node* left;
		Node* right;
		Node()
		{
			data=0;
			left=NULL;
			right=NULL;
		}
};
	
Node* getnode(int dat)
{
	Node* n=new Node;
	n->data=dat;
	n->left=NULL;
	n->right=NULL;
	return n;
}
Node* insert(Node* root1,int data)
{
	if (root1==NULL)
	{
		root1=getnode(data);
		return root1;
	}
	else 
	{
		if (root1->data>data)
		{
			root1->left=insert(root1->left,data);
		}
		else if (root1->data<data)
		{
			root1->right=insert(root1->right,data);
		}
		return root1;
	}
}


void preorder(Node* root)
{
	if (root==NULL)
	return;
	else 
	{
		stack <Node*> s;
		cout<<root->data<<'\t';
		s.push(root->right);
		s.push(root->left);
		while(!s.empty())
		{
			Node* n = s.top();
			cout<<n->data<<'\t';
			s.pop();
			if (n->right!=NULL)
			s.push(n->right);
			if (n->left!=NULL)
			s.push(n->left);
		}
	}
}

void postorder(Node* root)
{
	if (root==NULL)
	return;
	else
	{
		stack <Node*> s1,s2;
		s1.push(root->left);
		while(!s1.empty())
		{
			Node* n=s1.top();
			s2.push(n);
			s1.pop();
			if (n->left!=NULL)
			s1.push(n->left);
			if (n->right!=NULL)
			s1.push(n->right);
		}
		while(!s2.empty())
		{
			cout<<s2.top()->data<<'\t';
			s2.pop();
		}
		while(!s1.empty())
		{
			cout<<s1.top()->data<<'\t';
			s1.pop();
		}
		s1.push(root->right);
		while(!s1.empty())
		{
			Node* n=s1.top();
			s2.push(n);
			s1.pop();
			if (n->left!=NULL)
			s1.push(n->left);
			if (n->right!=NULL)
			s1.push(n->right);
		}
		while(!s1.empty())
		{
			cout<<s1.top()->data<<'\t';
			s1.pop();
		}
		while(!s2.empty())
		{
			cout<<s2.top()->data<<'\t';
			s2.pop();
		}
		cout<<root->data<<'\t';
	}
}


void inorder(Node* root)
{
	stack <Node*> s1,s2;
	s2.push(root->left);
	while(!s2.empty())
	{
		Node*n=s2.top();
		if(n->right!=NULL)
		s1.push(n->right);
		//s1.push(n);
		if (n->left!=NULL)
		s1.push(n->left);
		s2.pop();
		if (n->right!=NULL)
		s2.push(n->right);
		if (n->left!=NULL)
		s2.push(n->left);
	}
	//s1.pop();
	while(!s1.empty())
	{
		cout<<s1.top()->data<<'\t';
		s1.pop();
	}
	cout<<root->data<<'\t';
	s2.push(root->right);
	while(!s2.empty())
	{
		Node*n=s2.top();
		if(n->right!=NULL)
		s1.push(n->right);
		//s1.push(n);
		if (n->left!=NULL)
		s1.push(n->left);
		s2.pop();
		if (n->right!=NULL)
		s2.push(n->right);
		if (n->left!=NULL)
		s2.push(n->left);
	}
	//s1.pop();
	while(!s1.empty())
	{
		cout<<s1.top()->data<<'\t';
		s1.pop();
	}
}

void deleteTree(Node* root){
	if(root==NULL)
		return;
	else if(root->left==NULL || root->right==NULL)
	{
		delete root;
		return;
	}
	else
	{
		deleteTree(root->left);
		deleteTree(root->right);
	}
	
}

int main()
{
	Node* root=NULL;
	root=insert(root,23);
	insert(root,34);
	insert(root,20);
	insert(root,22);
	insert(root,18);
	// insert(root,36);
	// insert(root,33);
	// insert(root,19);
	// insert(root,21);
	// insert(root,31);
	// insert(root,32);
	cout<<"Preorder traversal is "<<endl;
	preorder(root);
	cout<<endl<<"Postorder traversal is "<<endl;
	postorder(root);
	cout<<endl<<"Inorder traversal is "<<endl;
	inorder(root);

}


