#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,i,j,flag=0,k=0,b=0;
    cin>>t;
    while (t > 0)
    {
        cin>>n>>k;
        int a[n];
        for(i=0;i<n;i++)
            cin>>a[i];
        for(i=0;i<n;i+=k)
        {
            for(j=i;j<k/2;j++)
            {
                b=a[j];
                a[j]=a[k-j-1];
                a[k-j-1]=b;
            }
        }
        for(j=n-(n%k);j<(n%k)/2;j++)
        {
            b=a[j];
            a[j]=a[(n%k)-j-1];
            a[(n-i-1)-j-1]=b;
        }
        for(i=0;i<n;i++)
            cout<<a[i];
        t--;
    }
    return 0;
}