#include<bits/stdc++.h>
using namespace std;

void printResult(int pages,float hits)
{
    cout<<"Total number of references: "<<pages<<endl;
    cout<<"Total number of page faults: "<<pages-hits<<endl;
    cout<<"Total number of hits: "<<hits<<endl;
    cout<<"Hit Ratio: "<<hits/pages<<endl;
}

void optimal(int pages,int frames,int* pagesArray)
{
    int framesArray[frames],index=1,flag = 0,i=0,j=0;
    float hits = 0;
    int h = 1;
    framesArray[0]=pagesArray[0];
    cout<<framesArray[0]<<" :\t"<<framesArray[0]<<"\tFault"<<endl;
    while(index<frames)
    {
        flag=0;
        if(framesArray[index-1] == pagesArray[h])
        {
            hits++;
            flag=1;
        }
        if(flag == 0)
        {
            framesArray[index]=pagesArray[h];
            index++;
            cout<<pagesArray[h]<<" :\t";
            for(j=0;j<index;j++)
            {
                cout<<framesArray[j]<<"\t";
            }
            cout<<"Fault"<<endl;
        }
        else
        {
            cout<<pagesArray[h]<<" :\t";
            for(j=0;j<index;j++)
            {
                cout<<framesArray[j]<<"\t";
            }
            cout<<"Hit"<<endl;
        }
        h++;
        if(h == pages) 
        {
            printResult(pages,hits);
            return;
        }
    }
    int k=0,replace,ind[frames],f=0,l=0;
    for(i=h;i<pages;i++)
    {
        flag=0;
        for(j=0;j<frames;j++)
        {
            if(pagesArray[i] == framesArray[j])
            {
                flag = 1;
                hits++;
                break;
            }
        }
        if(flag == 0)
        {
            for(k=0;k<frames;k++)
            {
                for(j=i+1;j<pages;j++)
                {
                    if(pagesArray[j] == framesArray[k])
                    {
                        ind[k]=j;
                        f=0;
                        break;
                    }
                    else 
                    {
                        f=1;
                        l=k;
                    }
                }
                if(f==1) break;
            }
            if(f == 0)
            {
                sort(ind,ind+frames);
                replace = pagesArray[ind[frames-1]];
            }
            else
            {
                replace = framesArray[l];
            }
            for(j=0;j<frames;j++)
            {
                if (framesArray[j] == replace)
                {
                    framesArray[j] = pagesArray[i];
                    break;
                }
            }
        }
        cout<<pagesArray[i]<<" :\t";
        for(j=0;j<frames;j++)
            cout<<framesArray[j]<<"\t";
        if(flag == 0)
            cout<<"Fault"<<endl;
        else
            cout<<"Hit"<<endl;
    }
    printResult(pages,hits);
}

int main()
{
    int pages,frames,i,j;
    cout<<"Enter the number of pages: ";
    cin>>pages;
    int pagesArray[pages];
    cout<<"Enter the page reference string: ";
    for(i=0;i<pages;i++)
    {
        cin>>pagesArray[i];
    }
    cout<<"Enter the number of frames: ";
    cin>>frames;
    optimal(pages,frames,pagesArray);
}