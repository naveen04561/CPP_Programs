#include<iostream>
using namespace std;
int main()
{
    int a[20],i,j,n,val,b;
    cout<<"Enter the no. of elements ";
    cin>>n;
    cout<<"enter the elements ";
    for (i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"Enter the value ";
    cin>>val;
    cout<<"Enter the position ";
    cin>>b;
    a[b]=val;
    cout<<"The new array is ";
    for (i=0;i<n;i++)
    {
        cout<<a[i]<<"\t";
    }

}