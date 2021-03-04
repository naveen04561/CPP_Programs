#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,i,j;
    cin>>t;
    while(t > 0)
    {
        cin>>n;
        int a[n],flag=0;
        for(i=0;i<n;i++)
            cin>>a[i];
        flag = a[n-1];
        for(i=n-2;i>=0;i--)
        {
            if(flag < a[i])
            {
                cout<<flag<<" ";
                flag = a[i];
            }
        }
        cout<<flag<<"\n";
        // for(i=0;i<n-1;i++)
        // {
        //     flag=0;
        //     for(j=i;j<n;j++)
        //     {
        //         if(a[i] < a[j])
        //             flag++;
        //     }
        //     if(flag == 0)
        //         cout<<a[i]<<" ";
        // }
        // cout<<a[n-1]<<"\n";
        t--;
    }
}