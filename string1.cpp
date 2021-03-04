#include<iostream>
#include<math.h>
#include<string>
using namespace std;

int str(string s1,int p)
{
    if (p==s1.length()-1)
    return 0;
    else
    {
        p++;
        return((s1[p]-48)*pow(10,s1.length()-p-1)+str(s1,p));
    }
}

int main()
{
    int y;
    string s;
    cout<<"Enter the string "<<endl;
    cin>>s;
    y=str(s,-1);
    cout<<y;
}