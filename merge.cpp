#include<iostream> 
using namespace std;
int main()
{
    int a[10],b[10],c[20],i,n1,n2;
    cout<<"Enter the no. of elements of the first array ";
    cin>>n1;
    cout<<"Enter the elements of the first array ";
    for(i=0;i<n1;i++)
    {
        cin>>a[i];
    }
    cout<<"Enter the no. of elements of the second array ";
    cin>>n2;
    cout<<"Enter the elements of the second array ";
    for (i=0;i<n2;i++)
    {
        cin>>b[i];
    }
    for (i=0;i<(n1);i++)
    {
        c[i]=a[i];
    }
    for (i=0;i<n2;i++)
    {
        c[i+n1]=b[i];
    }
    cout<<"The merged array is ";
    for (i=0;i<(n1+n2);i++)
    {
        cout<<c[i]<<"\t";
    }

}