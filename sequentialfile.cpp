// #include<iostream>
// using namespace std;

// int main()
// {
//     int files[50], i, start, length, j, c, k, count = 0;
//     for(i=0;i<50;i++)
//     files[i]=0;
//     while(1)
//     {
//         count=0;
//         cout<<"Enter starting block and length of files: ";
//         cin>>start>>length;
//         for(k=start;k<(start+length);k++)
//             if(files[k]==0)
//                 count++;
//         if(length==count)
//         {
//             cout<<"Files Allocated are:\n";
//             for(j=start;j<(start+length);j++)
//                 if(files[j]==0)
//                 {
//                     files[j]=1;
//                     cout<<j<<"\t"<<files[j]<<endl;
//                 }
//             if(j!=(start+length-1))
//                 cout<<"The files are allocated to disk\n";
//         }
//         else
//             cout<<"The files are not allocated \n";
//         cout<<"Do you want to enter more files? Enter 1 if YES else Enter 0 to exit: ";
//         cin>>c;
//         if(c==1)
//             continue;
//         else
//             break;
//     }
// }
#include<stdio.h>
#include<conio.h>
int main()
{
int f[50], i, start, length, j, c, k, count = 0;
for(i=0;i<50;i++)
f[i]=0;
printf("Files Allocated are : \n");
x: count=0;
printf("Enter startarting block and lengthgth of files:");
scanf("%d%d", &start,&length);
for(k=start;k<(start+length);k++)
if(f[k]==0)
count++;
if(length==count)
{
for(j=start;j<(start+length);j++)
if(f[j]==0)
{
f[j]=1;
printf("%d\t%d\n",j,f[j]);
}
if(j!=(start+length-1))
printf("The file is allocated to disk\n");
}
else
printf(" The file is not allocated \n");
printf("Do you want to enter more file(Yes - 1/No - 0)");
scanf("%d", &c);
if(c==1)
goto x;
else
return 0;
getch();
}