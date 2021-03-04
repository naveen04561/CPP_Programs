#include<iostream> 
using namespace std;
int main()
{
    int a[10]={10,20,30,40,50},mid,beg=0,end=4,val;
    cout<<"Enter the value to be searched ";
    cin>>val;
    int pos=-1;
    while (beg<=end)
    {
        mid=(beg+end)/2;
        if (a[mid]==val)
        {
            pos=mid;
            cout<<"the value is found at position"<<pos;
            break;
        }
        else if (a[mid]<val)
        end=mid-1;
        else 
        beg=mid+1;  
    }
    if (pos==-1)
    cout<<"Value not present ";
}