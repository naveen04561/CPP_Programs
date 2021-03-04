#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[] = {3,5,23,5,65,4},i=1,j,n=6,temp;
    while(i<n)
    {
        temp=a[j],j=i;
        while(a[j-1] > temp && j>0)
        {
            a[j]=a[j-1];
            j--;
        }
        a[j]=temp;
    }
    for(i=0;i<n;i++)
    cout<<a[i];
    return 0;
}