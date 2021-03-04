// #include<bits/stdc++.h>
// using namespace std;

// string twoStrings(string s1, string s2) {
//     map<char, int> s11;
//     int i,j=0;
//     for(i=0;i<s1.length();i++)
//     {
//         s11[s1[i]]=0;
//     }
//     for(i=0;i<s2.length();i++)
//     {
//         s11[s2[i]]=0;
//     }
//     for(i=0;i<s1.length();i++)
//     {
//         s11[s1[i]]++;
//     }
//     for(i=0;i<s2.length();i++)
//     {
//         if(s11[s2[i]] > 0){
//             j++;
//         }
//     }
//     if (j==0)
//         return "NO";
//     else
//         return "YES";
// }

// int main()
// {
//     string s1,s2;
//     cin>>s1>>s2;
//     cout<<twoStrings(s1,s2);
//     return 0;
// }

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n,q,i,j;
    cin>>n>>q;
    int* a[n];
    for(i=0;i<n;i++) 
    {
        int k;
        cin>>k;
        int c[k];
        for(j=0;j<k;j++)
            cin>>c[j];
        cout<<c<<"\n";
        a[i] = c;
        // delete[] c;
    }
    int i1,i2;
    for(i=0;i<q;i++)
    {
        cin>>i1>>i2;
        cout<<a[i1][i2]<<"\n";
    }
    return 0;
}