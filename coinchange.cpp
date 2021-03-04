#include<bits/stdc++.h>
using namespace std;

int main()
{
    int deno[]={1,10,5},n;
    cout<<"Enter the amount: ";
    cin>>n;
    sort(deno,deno+3);
    int k=2,sum=0;
    while (n!=0)
    {
        if ((n%deno[k])!=n)
        {
            int p=(n/deno[k]);
            sum+=p;
            n=n-p*deno[k];
        }
        k--;
    }
    cout<<sum<<endl;
}