#include<iostream>
using namespace std;
int main()
{
    int n,*a= new int[n],i,val,flag=0,b;
    cout<<"Enter the no. of elements ";
    cin>>n;
    for (i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"Enter the value to searched ";
    cin>>val;
    for (i=0;i<n;i++)
    {
        if (a[i]==val)
        {
            flag=1;
            b=i;
        }
    }
    if (flag==1)
    cout<<"value found at position: "<<b;
    else
    cout<<"value not found ";
    delete []a;
    
}