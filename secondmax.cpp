#include<iostream>
using namespace std;
int main()
{
    int a[20],i,n,b;
    cout <<"enter the no. of elements ";
    cin>>n;
    cout<<"enter the elements ";
    for (i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for (i=0;i<n;i++)
    {
        if (a[i]>a[i+1])
        {
            b=a[i];
            a[i]=a[i+1];
            a[i+1]=b;
        }
    }
    cout<<"Second maximum no. is "<<a[n-2];
}