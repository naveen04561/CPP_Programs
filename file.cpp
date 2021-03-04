#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
    ofstream fout("File");
    string name="naveen";
    fout<<name;
    ifstream fin("File");
    fin>>name;
    cout<<name;
}