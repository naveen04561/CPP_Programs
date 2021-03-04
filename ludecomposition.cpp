#include<iostream>
using namespace std;

int main()
{
    float a[20][20],c[10],b[10][10];
    int i,j;
    float x,y,z,y1,y2,y3;
    cout<<"Enter the coefficents and constants: ";
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
    c[0]=a[1][1];           //u11
    c[1]=a[1][2];           //u12
    c[2]=a[1][3];           //u13
    c[3]=a[2][1]/a[1][1];   //l21
    c[4]=(a[2][2]-c[3]*a[1][2]);        //u22
    c[5]=(a[2][3])-c[3]*a[1][3];        //u23
    c[6]=a[3][1]/a[1][1];               //l31
    c[7]=(a[3][2]-a[1][2]*c[6])/c[4];   //l32
    c[8]=a[3][3]-c[7]*c[5]-c[6]*a[1][3];//u33
    y1=a[1][4];
    y2=a[2][4]-y1*c[3];
    y3=a[3][4]-c[6]*y1-c[7]*y2;
    z=y3/c[8];
    y=(y2-c[5]*z)/c[4];
    x=(y1-c[1]*y-c[2]*z)/c[0];
    cout<<"The solutions are :"<<endl;
    cout<<'x='<<x<<endl<<'y='<<y<<endl<<'z='<<z;
}