#include<iostream>
using namespace std;

void TOH(int n,char beg, char aux, char end)
{
	if (n==1)
	{
		cout<<"Moving disk"<<n<<" from "<<beg<<" to "<<end<<endl;
	}
	
	else
	{
		TOH(n-1,beg,end,aux);
		cout<<"Moving disk"<<n<<" from "<<beg<<" to "<<end<<endl;
		TOH(n-1,aux,beg,end);
	}
}

int main()
{
	char A,B,C;
	int disks;
	cout<<"Enter the number of disks ";
	cin>>disks;
	TOH(disks,'A','B','C');
}
