#include<iostream>
using namespace std;
int main()
{
    int a=0,b=1,s,c,n,i;
    cout<<"Enter the no. of terms in fibonacci series ";
    cin>>c;
    if (c==1)
    cout<<a;
    else if (c==2)
    cout<<a<<b;
    else
    {
        cout<<a<<b;
        for (i=1;i<=(c-2);i++)
    {
        n=a+b;
        cout<<n;
        a=b;
        b=n;
    }
    }
}