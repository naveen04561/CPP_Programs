#include<iostream>
using namespace std;

void binary(int num)
{
    if(num!=0)
    {
        binary(num/2);
        cout<<(num%2);
    }
}

int main()
{
    int num;
    cout<<"Enter the number :";
    cin>>num;
    binary(num);
}