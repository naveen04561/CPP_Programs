#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n,q;
    cin>>n>>q;
    int *a[n];
    for (int i=0;i<n;i++)
    {
        int n1;
        cin>>n1;
        int *s = new int[n1];
        for (int j=0;j<n1;j++)
        cin>>s[j];
        a[i]=s;
    }
    // for (int i=0;i<q;i++)
    // {
    //     int c,b;
    //     cin>>c>>b;
    //     int *p = a[c];
    //     cout<<(*(p+b))<<endl;
    // }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        cout<<a[i][j];
    }
    return 0;
}