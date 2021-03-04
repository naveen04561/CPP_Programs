#include<bits/stdc++.h>
using namespace std;

void printResult(int pages,float hits)
{
    cout<<"Total number of references: "<<pages<<endl;
    cout<<"Total number of page faults: "<<pages-hits<<endl;
    cout<<"Total number of hits: "<<hits<<endl;
    cout<<"Hit Ratio: "<<hits/pages<<endl;
}

void lru(int pages,int frames,int* pagesArray)
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
    int k=0,replace,ind[frames];;
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
                replace = framesArray[k];
                for(j=i-1;j>=0;j--)
                {
                    if(pagesArray[j] == replace)
                    {
                        ind[k] = j;
                        break;
                    }
                }
            }
            sort(ind,ind+frames);
            replace = pagesArray[ind[0]];
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
    lru(pages,frames,pagesArray);
}