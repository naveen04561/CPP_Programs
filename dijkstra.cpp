#include<bits/stdc++.h>
using namespace std;
#define im 100
typedef pair<int,int> pi;

int main()
{
    int graph[][5] = {
        {0,0,6,6,0},
        {3,0,0,0,0},
        {0,0,0,2,0},
        {0,1,1,0,0},
        {0,4,0,2,0}
    };
    pi vertices[] = {make_pair(im,0),make_pair(im,1),make_pair(im,2),make_pair(im,3),make_pair(0,4)};
    priority_queue <pi> pq;
    for(auto i:vertices)
        pq.push(i);

    while(!pq.empty())
    {
        pi currentVertex = pq.top();
        pq.pop();
        int cv=currentVertex.second;
        for(int i=0;i<5;i++)
        {
            if(graph[cv][i]!=0 && graph[cv][i] + currentVertex.first < vertices[i].first)
            {
               vertices[i].first =  graph[cv][i] + currentVertex.first;
            }
        }
    }
    for(int i=0;i<5;i++)
    {
        cout<<vertices[i].first<<vertices[i].second<<endl;
    }
}