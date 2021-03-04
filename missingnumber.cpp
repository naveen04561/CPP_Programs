#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,j,t,flag;
    cin>>t;
    while (t > 0)
    {
        cin>>n;
        int a[n-1];
        for(i=0;i<n-1;i++)
            cin>>a[i];
        for(i=0;i<n-1;i++)
        {
            if((a[i]^(i+1))){
                flag = i+1;
                break;
            }
        }
        cout<<flag<<"\n";
        t--;
    }
    
    return 0;
}