#include<iostream>
using namespace std;
int main()
{
    int i,del,a[20]={20,30,40,50,60},n;
    cout<<"The array is ";
    for (i=0;i<5;i++)
    {
        cout<<a[i]<<"\t";
    }
    cout<<"Enter the element position to be deleted ";
    cin>>del;
    n=5;
    for (i=del;i<n;i++)
    {
        a[i]=a[i+1];
        n--;
    }
    cout<<"The array after deletion is ";
    for (i=0;i<5;i++)
    {
        cout<<a[i]<<"\t";
    }

}