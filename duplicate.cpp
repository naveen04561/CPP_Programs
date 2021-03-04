#include<iostream>
using namespace std;
int main()
{
    int a[20],n,i,j,b=0;
    cout<<"enter the no. of elements ";
    cin>>n;
    cout<<"enter the elements ";
    for (i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for (i=0;i<n;i++)
    {
        for (j=i+1;j<n;j++)

        {
            if (a[j]==a[i])
            {
                b=1;
                cout<<endl<<"The duplicated no. is "<<a[i]<<endl;
                cout<<"The positions are ";
                cout<<i<<"  "<<j;
            }
        }
    }
    if (b==0)
    cout<<"No duplications ";


}