#include <iostream> 
using namespace std;
int main()
{
    int i,n,b,j;
    int array[20];
    cout<<"Enter the no. of elements ";
    cin>>n;
    cout<<"Enter the elements ";
    for (i=0;i<n;i++)
      {
         cin>>array[i];
      }
    for (i=0;i<n;i++)
      {
          cout<<array[i]<<"\t";
      }  
      cout<<endl<<"The sorted array is "<<endl;
      for(i=0;i<n;i++)
      {
          for (j=0;j<n-i-1;j++)
          if (array[j]>array[j+1])
          {
              b=array[j];
              array[j]=array[j+1];
              array[j+1]=b;
          }
      }
      for (i=0;i<n;i++)
      cout<<array[i]<<" ";
}