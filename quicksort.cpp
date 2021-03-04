#include<bits/stdc++.h>
using namespace std;

void swap(int &a,int &b)
{
    int temp = a;
    a=b;
    b=temp;
}

int partition(int* a,int start,int end)
{
    int pivot = a[end];
    int pindex = start;
    for(int i=start;i<end;i++)
    {
        if(a[i]<=pivot)
        {
            swap(a[i],a[pindex]);
            pindex++;
        }
    }
    swap(a[pindex],a[end]);
    return pindex;
}

void quicksort(int a[],int start,int end)
{
    if(start<end)
    {
        int pivot=partition(a,start,end);
        quicksort(a,start,pivot-1);
        quicksort(a,pivot+1,end);
    }
}

int main()
{
    int a[]={100,51,122,23,700,836,44,51};
    quicksort(a,0,7);
    for(int i=0;i<8;i++)
    cout<<a[i]<<" ";
    return 0;
}