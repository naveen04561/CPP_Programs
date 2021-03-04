#include<iostream>
using namespace std;

// int func(int *a,int n,int div)
// {
//     int r=0,j,b=0,i;
//     // for (i=0;i<n;i++)
//     // {
//     //     if(r<=a[i]%div)
//     //     {
//     //         r=a[i]%div;
//     //         j=i;
//     //     }
//     // }
//     for (i=0;i<n;i++)
//     {
//         int c=a[i]%div;
//         int d=div-c;
//         if (c<=d)
//         {
//             b+=c;
//             a[i]-=c;
//         }
//         else 
//         {
//             j=i;
//             break;
//         }
//     }
//     for ( i=j;i<n;i++)
//     {
//         if (b>0)
//         {
//             int c=a[i]%div;
//             int d=div-c;
//             if (c>d)
//             {
//                 a[i]+=d;
//                 b-=d;
//             }
//         }
//         else break;
//     }
//     for (i=0;i<n;i++)
//     cout<<a[i]<<endl;
//     return b;
// }


// int main()
// {
//     int T;
//     cin>>T;
//     int n,div;
//     for (int i=0;i<T;i++)
//     {
//         cin>>n>>div;
//         int *a=new int[n];
//         for (int j=0;j<n;j++)
//         cin>>a[j];
//         cout<<func(a,n,div);
//     }
// }



