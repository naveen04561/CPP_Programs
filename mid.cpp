#include<iostream>
using namespace std;
void insert(int p[],int n,int val,int pos)
{
    int i;
    p[pos]=val;
    cout<<"After insertion ";
    for (i=0;i<n;i++)
    {
        cout<<p[i]<<"\t";
    }
}
int main()
{
    int val,pos;
    int a[20]={20,30,40,50,60};
    cout<<"enter the value";
    cin>>val;
    cout<<"enter the position";
    cin>>pos;
    insert(a,5,val,pos);
}