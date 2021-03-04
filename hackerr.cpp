#include <bits/stdc++.h>
using namespace std;

void minimumBribes(int* q,int n) {
    int i,j,shifts = 0,temp=0;
    for(i=0;i<n;i++)
    {
        if(q[i]!=i+1)
        {
            if(abs(q[i] - (i+1)) > 2)
            {
                cout<<"Too chaotic\n";
                return;
            }
            else
            {
                if( abs(q[i] - (i+1)) == 2)
                {
                    temp = q[i];
                    q[i] = q[i+1];
                    q[i+1] = temp;
                    temp = q[i+1];
                    q[i+1] = q[i+2];
                    q[i+2] = temp;
                    shifts+=2;
                }
                else if( abs(q[i] - (i+1)) == 1)
                {
                    temp = q[i];
                    q[i] = q[i+1];
                    q[i+1] = temp;
                    shifts+=1;
                }
            }
        }
    }
    cout<<shifts<<"\n";
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        int q[n];
        for (int i = 0; i < n; i++) {
            cin>>q[i];
        }
        minimumBribes(q,n);
    }

    return 0;
}