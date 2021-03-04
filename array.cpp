#include <iostream>
using namespace std;
int main()
{
    int i,n;
    int *array= new int[n];
    cout<<"Enter the no. of elements ";
    cin>>n;
    cout<<"Enter the elements ";
    for (i=0;i<n;i++)
      {
         cin>>array[i];
      }
    for (i=0;i<n;i++)
      {
          cout<<array[i]<<endl;
      }
      array++;
      for(i=0;i<n;i++)
      {
        cout<<array[i]<<endl;
      }
}
