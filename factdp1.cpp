#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the number whose factorial is to be found :";
    cin>>n;
    int* ar = new int[n+1];
    ar[0]=1;
    for (int i=1;i<=n;i++)
    {
        ar[i]=((i%1000000007)*(ar[i-1]%1000000007))%1000000007;
    }
    cout<<ar[n];
}