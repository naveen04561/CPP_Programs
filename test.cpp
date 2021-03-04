#include<iostream>
using namespace std;


int main()
{
    int a[]={1,2,3,4,5,2,1},mid,beg=0,end=6,pos=-1;
    while(beg<=end)
    {
        mid=(beg+end)/2;
        if (a[mid-1]<a[mid]&&a[mid]>a[mid+1])
        {
            pos=mid;
            cout<<"the value is found at position "<<pos;
            break;
        }
        else if (a[mid-1]<a[mid]&&a[mid+1]>a[mid])
            beg=mid+1;
        else
            end=mid-1;  
    }
}