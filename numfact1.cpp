#include<bits/stdc++.h>
using namespace std;

int getnum(int n,int a[])
{
    if (n==0 || n==1 || n==2)
        a[n]=1;
    else if (n==3)
        a[n]=2;
    else if (a[n]==0)
    {
        int sub1 = getnum(n-1,a);
        int sub3 = getnum(n-3,a);
        int sub4 = getnum(n-4,a);
        a[n]=sub1+sub4+sub3;
    }
    return a[n];
}


int main()
{
    int n,*dp;
    cout<<"Enter the number whose factor is to be found :";
    cin>>n;
    dp = new int[n+1];
    cout<<getnum(n,dp);
}