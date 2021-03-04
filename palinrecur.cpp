#include<iostream>
using namespace std;

bool palin(string s1,int i)
{
    if(s1[s1.length()-1]==s1[i])
    {
        palin(s1,i+1);
        return true;
    }
    else
    return false;
}

int main()
{
    string s;
    cout<<"Enter the string :";
    cin>>s;
    if (palin(s,0))
    cout<<"Is a palindrome "<<endl;
    else
    cout<<"Not a palindrome "<<endl;
}