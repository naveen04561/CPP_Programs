#include<iostream>
using namespace std;

void Merge(int a1[],int a2[],int a3[],int n)
{
    int i,j,k;
    i=0,j=0;
    while(i<n && j<n)
    {
        if (a1[i]<=a2[j])
        {
            a3[k]=a1[i];
            i++;
        }
        else
        {
            a3[k]=a2[j];
            j++;
        }
        k++;
    }
    while(i<n)
    {
        a3[k]=a1[i];
        i++;
        k++;
    }
    while(j<n)
    {
        a3[k]=a2[j];
        j++;
        k++;
    }
}


int main()
{
    int n;
    cout<<"Enter the number of elements of the arrays: ";
    cin>>n;
    int a1[n];
    int a2[n];
    int a3[2*n];
    cout<<"Enter the elements: ";
    for (int i=0;i<n;i++)
    cin>>a1[i];
    for (int i=0;i<n;i++)
    cin>>a2[i];
    int l1=n/2;
    int l2=n+n/2;
    Merge(a1,a2,a3,n);
    for (int i=0;i<2*n;i++)
    {
        cout<<a3[i]<<"  ";
    }
    //cout<<"Median = "<<((a3[n/2]+a3[n/2-1])/2)<<endl;
}