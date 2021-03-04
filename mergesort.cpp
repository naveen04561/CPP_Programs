#include<iostream>
using namespace std;

void Merge(int a[],int l,int m,int r)
{
    int i,j;
    int n1=m-l+1;
    int n2=r-m;
    int la[n1];
    int ra[n2];
    for (i = 0; i < n1; i++) 
        la[i] = a[l + i]; 
    for (j = 0; j < n2; j++) 
        ra[j] = a[m + 1+ j];
    int k=l;
    i=0,j=0;
    while(i<n1 && j<n2)
    {
        if (la[i]<=ra[j])
        {
            a[k]=la[i];
            i++;
        }
        else
        {
            a[k]=ra[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        a[k]=la[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        a[k]=ra[j];
        j++;
        k++;
    }
}

void MergeSort(int a[],int l,int r)
{
    if (l>=r)
    return;
    else
    {
        int m=(l+r)/2;
        MergeSort(a,l,m);
        MergeSort(a,m+1,r);
        Merge(a,l,m,r);
    }
    
}

int main()
{
    int n;
    cout<<"Enter the number of elements :";
    cin>>n;
    int *a=new int[n];
    cout<<"Enter the elements :";
    for (int i=0;i<n;i++)
    cin>>a[i];
    MergeSort(a,0,n-1);
    for (int i=0;i<n;i++)
    cout<<a[i];
}