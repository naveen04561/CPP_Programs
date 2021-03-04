#include<iostream> 
using namespace std;
int main()
{
    int a[20],i,n,b;
    cout<<"Enter the no. of elements ";
    cin>>n;
    cout<<"Enter the elements ";
    for (i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for (i=0;i<(n)/2;i++)
    {
        b=a[i];
        a[i]=a[n-i-1];
        a[n-i-1]=b;
    }
    cout<<"The reversed array is"<<endl;
    for (i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}