#include<iostream>
using namespace std;
int fibo (int n,int x,int y)
{
	if (n==0)
	return 0;
	else
	{
		cout<<(x+y)<<endl;
		return (fibo(n-1,x+y,x));
	}
}


int main()
{
	int a=0,b=1,v,n;
	cout<<"Enter the no. of terms : ";
	cin>>n;
	cout<<a<<endl<<b<<endl;
	v=fibo(n-2,b,a);
}