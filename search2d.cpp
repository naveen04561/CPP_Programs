#include<bits/stdc++.h>
using namespace std;

int search(int N,int M, int X, vector<vector<int> > mat)
{
    int b = 0;
    int i=0,j=0,k=0;
    for(i=0;i<N;i++)
    {
        if(X<mat[i][0])
        return 0;
        if(mat[i][0] <= X && mat[i][M-1] >= X)
        {
            for(k=0;k<M;k++)
            {
                if (mat[i][k] == X)
                {
                    b = 1;
                    break;
                }
            }
            return b;
        }
        else
        return 0;
    }
}


int main()
{
    int n,m,x;
    cin>>n>>m;
    vector<vector<int> >mat(n, vector<int>(m));
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
    cin>>mat[i][j];
    cin>>x;
    cout<<search(n,m,x,mat);
}