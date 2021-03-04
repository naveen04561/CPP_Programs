#include<bits/stdc++.h>
using namespace std;

int main()
{
    int v,e;
    cout<<"Enter the number of edges vertices and edges in the graph:";
    cin>>v>>e;
    int graph[v][v];
    for(int i=0;i<v;i++)
        for(int j=0;j<v;j++)
            cin>>graph[i][j];
    bool visited[v];
    for(int i=0;i<v;i++)
        visited[i] = false;
    queue <int> q;
    // stack <int> q;
    q.push(1);
    while(!q.empty())
    {
        int top=q.front();
        q.pop();
        if(visited[top] == false)
        {
            cout<<top<<endl;
            visited[top] = true;
        }
        for(int i=0;i<v;i++)
        {
            if(graph[top][i] != 0 && visited[i] == false)
                q.push(i);
        }
    }
}