#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    int v[n];
    for(int i=0;i<n;i++)
    v[i]=1;
    int max=0;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(a[i]>a[j] && v[i] < v[j] + 1)
                v[i] = v[j] + 1;
        }
    }
    max = v[0];
    for(int i=0;i<n;i++)
    {
        cout<<v[i]<<" ";
        if(max<v[i])
        max=v[i];
    }
    cout<<"\n"<<max<<"\n";
}