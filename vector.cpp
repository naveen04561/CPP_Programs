#include<bits/stdc++.h>
using namespace std;


int main() {
    // vector<int>v = {10,90,86,43,22,34};
    // int n,a;
    // cin>>n;
    // for(int i=0;i<n;i++)
    // {
    //     cin>>a;
    //     v.push_back(a);
    // }
    // sort(v.begin(),v.begin()+3);
    // partial_sort(v.begin(),v.begin()+3,v.end());
    // for(vector<int>::iterator itr=v.begin();itr<v.end();itr++)
    // {
    //     cout<<*itr<<" ";
    // }
    // set<int, greater<int> > s;
    // for(int i=0;i<3;i++)
    // {
    //     cin>>a;
    //     s.insert(a);
    // }
    // set<int, greater<int> > ::iterator itr;
    // for(itr=s.begin();itr!=s.end();itr++)
    // cout<<*itr;
    int n,m,i=0,j=0,a;
    set <int,greater<int> > scores;
    vector<int> alice; 
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a;
        scores.insert(a);
    }
    cin>>m;
    for(i=0;i<m;i++)
    {
        cin>>a;
        alice.push_back(a);
    }
    set <int ,greater<int> > :: iterator itr;
    // for(itr=scores.begin();itr!=scores.end();itr++)
    //     cout<<*itr;
    i=0;
    while(1)
    {
        int c=0;
        for(itr=scores.begin();itr!=scores.end();itr++)
        {
            if(alice[i]>=(*itr))
            {
                cout<<c+1<<"\n";
                i++;
                break;
            }
            c++;
        }
        if(itr == scores.end())
        {
            cout<<scores.size()+1<<"\n";
            i++;
        }
        if(i == alice.size())
        break;
    }
    return 0;
}
