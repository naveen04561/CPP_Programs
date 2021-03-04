#include<bits/stdc++.h>
#include<string.h>
using namespace std;

int count(int dp[],int l,string s1,string s2,int i)
{
    if(i<(l-1))
    {
        if (s1[i]=!s2[i])
        {
            dp[i]=1;
            i++;
            dp[i]+=dp[i-1];
            return(count(dp,l,s1,s2,i));
        }
        else
        {
            i++;
            return (count(dp,l,s1,s2,i));
        }
        
    }
    else if ((i==l-1))
    {
        if(s1[i]!=s2[i])
        {
            dp[i]=1;
            dp[i]+=dp[i-1];
        }
        else{
        dp[i]+=dp[i-1];
        i++;
        return (count(dp,l,s1,s2,i));
        }
    }
    else 
    return dp[l-1];
}

int main()
{
    string s1,s2;
    cout<<"Enter the strings :";
    cin>>s1>>s2;
    int* ar = new int[s1.length()];
    for (int i=0;i<s1.length();i++)
        ar[i]=0;
    // for (int i=0;i<(s1.length()-s2.length());i++)
    //     s2+='@';
    cout<<count(ar,s1.length(),s1,s2,0);
    return 0;
}