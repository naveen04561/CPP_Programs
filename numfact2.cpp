#include<iostream>
using namespace std;

int main()
{
    int n,* dp;
    cout<<"Enter the number :";
    cin>>n;
    dp = new int [n];
    dp[0]=1;
    dp[1]=1;
    dp[2]=1;
    dp[3]=2;
    for (int i=4;i<n+1;i++)
    {
        dp[i]=dp[i-1]+dp[i-3]+dp[i-4];
    }
    cout<<dp[n];
    delete dp;
}