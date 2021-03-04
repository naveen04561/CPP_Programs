#include<iostream> 
using namespace std;

int main()
{
    int t,n,i,j,equilp,flag=0,c=0,lsum=0,rsum=0;
    cin>>t;
    while(t > 0)
    {
        cin>>n;
        int a[n];
        for(i=0;i<n;i++)
            cin>>a[i];
        equilp = n/2;
        while(1)
        {
            lsum = 0,rsum = 0;
            for(i=0;i<equilp;i++)
                lsum+=a[i];
            for(i=equilp+1;i<n;i++)
                rsum+=a[i];
            if(lsum > rsum)
            {
                equilp--;
                flag++;
            }
            else if(lsum < rsum)
            {
                equilp++;
                flag++;   
            }
            else if(lsum == rsum)
            {
                c=0;
                break;
            }
            if(flag == n/2)
            {
                c=1;
                break;
            }
        }
        c == 0 ? cout<<equilp<<"\n" : cout<<"-1\n";
        t--;
    }
}