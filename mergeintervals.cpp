#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n][2];
    for(int i=0;i<n;i++)
    {
        cin>>a[i][0]>>a[i][1];
    }
    vector<vector<int> >v;
    int j = 0;
    vector<int> x;
    x.push_back(a[0][0]);
    x.push_back(a[0][1]);
    v.push_back(x);
    for(int i=1;i<n;i++)
    {
        vector<int> v1;
        if(v[j][1] >= a[i][0])
        {
            v1.push_back(a[j][0]);
            v1.push_back(a[i][1]);
            v.push_back(v1);
        }
        else
        {
            j = i;
            v1.push_back(a[i][0]);
            v1.push_back(a[i][1]);
            v.push_back(v1);
        }
    }
    for(auto x: v)
    {
        cout<<x[0]<<" "<<x[1]<<"\n";
    }
    return 0;
}