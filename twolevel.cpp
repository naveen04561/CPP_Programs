//TWO LEVEL DIRECTORY ORGANIZATION
#include<iostream>
using namespace std;

struct twoLevel
{
    string directoryName,fileName[10];
    int fileCount;
};

int main()
{
    twoLevel dir[10];
    int i,ch,directoryCount,k;
    string f, d;
    directoryCount=0;
    while(1)
    {
        cout<<"\n1.Create Directory\t 2.Create File\t 3.Delete File";
        cout<<"\n4.Search File \t \t 5.Display \t 6.Exit \nEnter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1: cout<<"\nEnter name of directory: ";
                    cin>>dir[directoryCount].directoryName;
                    dir[directoryCount].fileCount=0;
                    directoryCount++;
                    cout<<"Directory created";
                    break;

            case 2: printf("\nEnter name of the directory: ");
                    cin>>d;
                    for(i=0;i<directoryCount;i++)
                        if(d == dir[i].directoryName)
                        {
                            cout<<"Enter name of the file: ";
                            cin>>dir[i].fileName[dir[i].fileCount];
                            dir[i].fileCount++;
                            cout<<"File created";
                            break;
                        }
                    if(i==directoryCount)
                        cout<<"Directory "<<d<<" not found";
                    break;

            case 3: cout<<"\nEnter name of the directory: ";
                    cin>>d;
                    for(i=0;i<directoryCount;i++)
                    {
                        if(d == dir[i].directoryName)
                        {
                            cout<<"Enter name of the file: ";
                            cin>>f;
                            for(k=0;k<dir[i].fileCount;k++)
                            {
                                if(f == dir[i].fileName[k])
                                {
                                    cout<<"File "<<f<<" is deleted ";
                                    dir[i].fileCount--;
                                    dir[i].fileName[k] = dir[i].fileName[dir[i].fileCount];
                                    goto jmp;
                                }
                            }
                            cout<<"File "<<f<<" not found";
                            goto jmp;
                        }
                    }
                    cout<<"Directory "<<d<<" not found";
                    jmp : break;

            case 4: cout<<"\nEnter name of the directory: ";
                    cin>>d;
                    for(i=0;i<directoryCount;i++)
                    {
                        if(d == dir[i].directoryName)
                        {
                            cout<<"Enter the name of the file: ";
                            cin>>f;
                            for(k=0;k<dir[i].fileCount;k++)
                            {
                                if(f == dir[i].fileName[k])
                                {
                                    cout<<"File "<<f<<" is found";
                                    goto jmp1;
                                }
                            }
                            cout<<"File "<<f<<" not found";
                            goto jmp1;
                        }
                    }
                    cout<<"Directory "<<d<<" not found";
                    jmp1: break;

            case 5: if(directoryCount==0)
                        cout<<"\nNo Directories ";
                    else
                    {
                        cout<<"\nDirectory\tFiles";
                        for(i=0;i<directoryCount;i++)
                        {
                            cout<<"\n"<<dir[i].directoryName<<"\t";
                            for(k=0;k<dir[i].fileCount;k++)
                                cout<<"\t"<<dir[i].fileName[k];
                        }
                    }
                    break;
            default:exit(0);
        }
    }
}

