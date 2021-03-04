#include<iostream>
using namespace std;

int main()
{
    float a[20][20];
    int i,j,m=0,b=0;
    float x0,y0,z0,x,y,z;
    cout<<"Enter the coefficents and constants of equations of the form ax+by+cz=d: ";
    for (i=1;i<=3;i++)
    {
        for (j=1;j<=3+1;j++)
        {
            cin>>a[i][j];
        }
    }
    for (i=1;i<=3;i++)
    {
        for(j=1;j<=3;j++)
        {
            cout<<a[i][j]<<'\t';
        }
        cout<<endl;
    }
    cout<<"Enter the initial values of x,y,z :";
    cin>>x0>>y0>>z0;
    cout<<"Enter the number of iterations :";
    cin>>m;
    while(b<m)
    {
        x=(a[1][4]-(a[1][2]*y0)-(a[1][3]*z0))/(a[1][1]);
        y=(a[2][4]-(a[2][1]*x)-(a[2][3]*z0))/(a[2][2]);
        z=(a[3][4]-(a[3][1]*x)-(a[3][2]*y))/(a[3][3]);
        cout<<'x'<<b+1<<'='<<x<<' '<<'\t'<<'y'<<b+1<<'='<<y<<'\t'<<'z'<<b+1<<'='<<z<<endl;
        y0=y,z0=z;
        b++;
    }
}