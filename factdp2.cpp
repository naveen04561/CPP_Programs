#include<bits/stdc++.h>
using namespace std;

int fact(int n,int *a)
{
    if (n==0)
    return 1;
    else 
    {
        if (a[n]==0)
            a[n]= n*fact(n-1,a);
        return a[n];
    }
}

int main()
{
    int n,i;
    cout<<"Enter the number whose fatcorial is to be found :";
    cin>>n;
    int *ar = new int [n+1];
    for (i=0;i<=n;i++)
    ar[i]=0;
    cout<<fact(n,ar);
}