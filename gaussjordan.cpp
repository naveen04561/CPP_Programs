#include<iostream>
using namespace std;

int main()
{
    float a[20][20];
    int i,j,m=0;
    float b,c,x,y,z;
    cout<<"Enter the coefficents and constants: ";
    for (i=1;i<=3;i++)
    {
        for (j=1;j<=4;j++)
        {
            cin>>a[i][j];
        }
    }
    b=a[1][1];
    for (j=1;j<=3+1;j++)
    {
        a[1][j]=a[1][j]/b;
    }
    b=a[2][1];
    c=a[3][1];
    for (j=1;j<=4;j++)
    {
        a[2][j]=a[2][j]-b*a[1][j];
        a[3][j]=a[3][j]-c*a[1][j];
    }
    c=a[2][2];
    for (j=2;j<=4;j++)
    {
        a[2][j]=a[2][j]/c;
    }
    c=a[3][2];
    for (j=1;j<=4;j++)
    {
        a[3][j]=a[3][j]-c*a[2][j];
    }
    if(a[3][3]!=0){
    c=a[3][3];
    for (j=3;j<=4;j++)
    a[3][j]/=c;
    }
    cout<<"The reduced row echoln form is"<<endl;
    for (i=1;i<=3;i++)
    {
        for (j=1;j<=4;j++)
        {
            cout<<a[i][j]<<"\t";
        }
        cout<<endl;
    }
    for (j=1;j<=4;j++)
    {
        if (a[3][j]==0)
        m++;
    }
    if (m==4)
    {
        for (j=1;j<=4;j++)
        {
            if (a[2][j]==0)
            c++;
        }
        }
    if (m==2)
    {
        cout<<"Rank of matirx is equal to augmented matrix and is full "<<endl;
        cout<<"Hence unique solution."<<endl;
        cout<<"The solution is:"<<endl;
        z=a[3][4]/a[3][3];
        y=a[2][4]-a[2][3]*z;
        x=a[1][4]-a[1][3]*z-a[1][2]*y;
        cout<<"x="<<x<<"\t"<<"y="<<y<<"\t"<<"z="<<z<<endl;
    }
    else if (m==4&&c!=4)
    {
        cout<<"Rank of matrix and augmented matrix is same and is 2, not full. "<<endl;
        cout<<"Hence there are infinitely many solutions. "<<endl;
    }
    else if (a[3][1]==0&&a[3][2]==0&&a[3][3]==0&&a[3][4]!=0)
    cout<<"Rank of matrix is not equal to augmented matrix , hence no solution. "<<endl;
}