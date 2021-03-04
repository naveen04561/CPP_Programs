#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i;
	cout<<"Enter the number of processes : ";
	cin>>n;
	float at[n],bt[n],tq;
	for(i=0;i<n;i++)
	{
		cout<<"Enter the values of arrival time and burst time of the "<<i+1<<" process"<<endl;
		cin>>at[i]>>bt[i];
	}
    cout<<"Enter the Time Quantum :";
    cin>>tq;
	float ct[n],ta[n],wt[n],atc[n],btc[n],temp;
    bool atcc[n];
    queue <int> q;
    queue <int> q1;
    float min=at[0];
    float max=at[0];
    int n1=0;
    for (i=0;i<n;i++)
    {
        atc[i]=at[i];
        btc[i]=bt[i];
        atcc[i]=false;
        if(at[i]<min)
        {
            min=at[i];
        }
        if (at[i]>max)
		{
			max=at[i];
		}
    }
    float ctt=min;
    string s1,s2;
    for (i=0;i<n;i++)
    {
        if (at[i]==min)
        {
            q.push(i);
            n1++;
            atcc[i]=true;
        }
    }
    int ind,t=min;
    q1.push(t);
    while(!q.empty())
    {
        ind=q.front();
        temp=btc[ind];
		atc[ind]=max+1;
		min=max+1;
        q.pop();
        s2=48+ind+1;
        s1+='P'+s2+'\t';
        for (i=0;i<n;i++)
        {
            if (atc[i]<min)
            {
                min=atc[i];
            }
        }
        if(temp<=tq)
        {
            t+=temp;
            q1.push(t);
            ctt+=temp;
            ct[ind]=ctt;
            btc[ind]-=temp;
            if (n1<=n)
            {
                if(min-ctt>0)
                    ctt+=(min-ctt);
                for(i=0;i<n;i++)
                {
                    if (at[i]<=ctt && atcc[i]==false)
                    {
                        q.push(i);
                        n1++;
                        atcc[i]=true;
                    }
                }
            }
        }
        else
        {
            t+=tq;
            q1.push(t);
            ctt+=tq;
            btc[ind]-=tq;
            if (n1<=n)
            {
                if(min-ctt>0)
                    ctt+=(min-ctt);
                for(i=0;i<n;i++)
                {
                    if (at[i]<=ctt && atcc[i]==false)
                    {
                        q.push(i);
                        n1++;
                        atcc[i]=true;
                    }
                }
            }
            q.push(ind);
        }
    }
    float sumta=0,sumwt=0;
	for(int i=0;i<n;i++)
	{
		ta[i]=ct[i]-at[i];
		wt[i]=ta[i]-bt[i];
		sumta+=ta[i];
		sumwt+=wt[i];
	}
	float avgtat=sumta/n;
	float avgwt=sumwt/n;
    cout<<"Gauntt Chart"<<endl;
    cout<<"\t";
    cout<<s1<<endl;
    while(!q1.empty())
    {
        cout<<q1.front()<<"\t";
        q1.pop();
    }
    cout<<endl<<endl<<"Pno."<<"\t"<<"AT"<<"\t"<<"BT"<<"\t"<<"CT"<<"\t"<<"TAT"<<"\t"<<"WT"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<i+1<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<ct[i]<<"\t"<<ta[i]<<"\t"<<wt[i]<<"\t"<<endl;
	}
	cout<<"Average Turn Around Time : "<<avgtat<<endl;
	cout<<"Average Waiting Time :"<<avgwt<<endl;
}