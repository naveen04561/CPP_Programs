#include<iostream>
using namespace std;

int main()
{
    // int ar[3][3]={
    //     {10,20,30},{16,26,35},{27,29,37}
    // };
    // int x=29;
    // for (int i=0;i<3;i++)
    // {
    //     if(ar[i][0]==x)
    //     {
    //         cout<<i<<"0"<<endl;
    //     }
    //     else if (ar[i][0]<x){
    //         if(ar[i][1]==x)
    //         {
    //             cout<<i<<"1"<<endl;
    //         }
    //         else if (ar[i][1]<x)
    //         {
    //             if (ar[i][2]==x)
    //             {
    //                 cout<<i<<"2"<<endl;
    //             }
    //         }
    //     }
    // }

    int n,i=0,j=0,temp;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int ar[n];
    cout<<"Enter the elements: ";
    for(i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    for(i=0;i<n;i++)
    {
        if (ar[j] == j+1)
        {
            j++;
        }
        else
        {
            temp = ar[ar[j]-1];  
            ar[ar[j]-1] = ar[j];
            ar[j] = temp;
        }
    }
    for(i=0;i<n;i++)
    {
        cout<<ar[i]<<" ";
    }
}