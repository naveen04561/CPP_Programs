// #include<iostream>
// using namespace std;

// int main()
// {
//     int t,n,s,i,j;
//     cin>>t;
//     while(t>0)
//     {
//         cin>>n>>s;
//         int a[n],sum = 0,b1 = 0,b2 = 0,flag = 0;
//         for(i=0;i<n;i++)
//             cin>>a[i];
//         // for(i=0;i<n;i++)
//         // {
//         //     sum = 0;
//         //     b1=i+1;
//         //     for(j=i;j<n;j++)
//         //     {
//         //         sum+=a[j];
//         //         if(sum == s)
//         //         {
//         //             b2=j+1;
//         //             flag = 1;
//         //             break;
//         //         }
//         //     }
//         //     if(flag == 1)
//         //         break;
//         // }
//         b1 = 1;
//         for(i=0;i<n;i++)
//         {
//             sum+=a[i];
//             if(sum > s)
//             {
//                 sum-=a[b1-1];
//                 b1+=1;
//             }
//             if(sum == s)
//             {
//                 flag=1;
//                 b2 = i+1;
//                 break;
//             }
//         }
//         if(flag == 0)
//             cout<<"-1"<<endl;
//         else
//             cout<<b1<<" "<<b2<<endl;
//         t--;
//     }
//     return 0;
// }
#include <iostream>
using namespace std;

int main() 
{
	int t,n,i,j;
    cin>>t;
    while(t>0)
    {
        cin>>n;
        int a[n],n0 = 0,n1 = 0,n2 = 0;
        for(i=0;i<n;i++)
            cin>>a[i];
        for(i=0;i<n;i++)
        {
            if(a[i] == 0)
                n0+=1;
            else if(a[i] == 1)
                n1+=1;
            else
                n2+=1;
        }
        cout<<n0<<" "<<n1<<" "<<n2<<"\n";
        for(i=0;i<n0;i++)
            a[i] = 0;
        for(i=n0;i<n1+n0;i++)
            a[i] = 1;
        for(i=n1+n0;i<n2+n1+n0;i++)
            a[i] = 2;
        for(i=0;i<n;i++)
            cout<<a[i]<<" ";
        cout<<"\n";
        t--;
    }
	return 0;
}