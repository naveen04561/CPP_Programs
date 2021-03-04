// SINGLE LEVEL DIRECTORY ORGANIZATION

#include<iostream>
using namespace std;

struct singleLevel
{
    string directoryName,fileName[10];
    int fileCount;
};


int main()
{
    singleLevel dir;
    int i,ch;
    string f;
    dir.fileCount = 0;
    cout<<"Enter name of directory: ";
    cin>>dir.directoryName;
    while(1)
    {
        cout<<"\n1.Create File\n2.Delete File\n3.Search File\n4.Display Files\n5.Exit\nEnter your choice: ";
        cin>>ch;
        switch(ch)
        {
            case 1: cout<<"\nEnter the name of the file: ";
                    cin>>dir.fileName[dir.fileCount];
                    dir.fileCount++;
                    break;

            case 2: cout<<"\nEnter the name of the file: ";
                    cin>>f;
                    for(i=0;i<dir.fileCount;i++)
                    {
                        if(f == dir.fileName[i])
                        {
                            cout<<"\nFile "<<f<<" is deleted ";
                            dir.fileName[i] = dir.fileName[dir.fileCount-1];
                            break;
                        }
                    }
                    if(i==dir.fileCount)
                        cout<<"File "<<f<<" not found";
                    else
                        dir.fileCount--;
                    break;
            case 3: cout<<"\nEnter the name of the file: ";
                    cin>>f;
                    for(i=0;i<dir.fileCount;i++)
                    {
                        if(f == dir.fileName[i])
                        {
                            cout<<"File "<<f<<" not found";
                            break;
                        }
                    }
                    if(i==dir.fileCount)
                        cout<<"File "<<f<<" not found";
                    break;
            case 4: if(dir.fileCount==0)
                        cout<<"\nDirectory Empty";
                    else
                    {
                        cout<<"\nThe Files are: ";
                        for(i=0;i<dir.fileCount;i++)
                            cout<<dir.fileName[i]<<"\t";
                    }
                    break;
            default: exit(0);
        }
    }
}