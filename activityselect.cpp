#include<bits/stdc++.h>
using namespace std;

struct Activity{
    char jobId;
    int start;
    int finish;
};

bool ActComp(Activity s1,Activity s2)
{
    return (s1.finish < s2.finish);
}
int main()
{
    Activity ar[]={{'a',5,9},{'b',1,2},{'c',3,4},{'d',0,6}};
    int n = sizeof(ar)/sizeof(ar[0]);
    sort(ar,ar+n,ActComp);
    Activity complete[n];
    complete[0]=ar[0];
    cout<<ar[0].jobId<<endl;
    int j=1;
    for (int i=1;i<n;i++)
    {
        if (ar[i].start>=complete[i-j].finish)
        {
            complete[i]=ar[i];
            cout<<ar[i].jobId<<endl;
            j++;
        }
    }
}