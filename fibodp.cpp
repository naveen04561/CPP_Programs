#include<iostream>
using namespace std;

int fibo(int n,int* a)
{
    if(n==0 || n==1)
    return 0;
    else if(n==2)
    return 1;
    else
    {
        a[n]=(fibo(n-1,a)%1000000007+fibo(n-2,a)%1000000007)%1000000007;
        return a[n];
    }
    
}

int main()
{
    int n,i;
    cout<<"Enter the number :";
    cin>>n;
    int f[n+2];
    f[0]=0,f[1]=1;
    for (i=2;i<=n;i++)
    {
        f[i]=f[i-1]+f[i-2];
    }
    cout<<f[n-1]<<endl; 
    cout<<fibo(n,f)<<endl;
}