#include<bits/stdc++.h>
using namespace std;

typedef pair<float,int> pi;

int main()
{
	int n,i;
	cout<<"Enter the number of processes : ";
	cin>>n;
	float *at=new float[n];
	float *bt=new float[n];
	for( i=0;i<n;i++)
	{
		cout<<"Enter the values of arrival time and burst time of the "<<i+1<<" process"<<endl;
		cin>>at[i]>>bt[i];
	}
	float *ct=new float[n];
	float *ta=new float[n];
	float *wt=new float[n];
	float *atc=new float[n];
	float min=at[0];
	float max=at[0];
    bool *atcc=new bool[n];
    // string s1,s2,s3;
	for ( i=0;i<n;i++)
	{
        atcc[i]=false;
		atc[i]=at[i];
		if (at[i]<min)
		{
			min=at[i];
		}
		if (at[i]>max)
		{
			max=at[i];
		}
	}
	int n1=0;
	priority_queue <pi,vector<pi>, greater<pi> > pq;
    float count=min;
    for (i=0;i<n;i++)
    {
        if (at[i]==min){
            pq.push(make_pair(bt[i],i));
            atcc[i]=true;
            n1++;
        }
    }
    int l;
    float j;
    while(!pq.empty())
    {
        
            l=pq.top().second;
            j=pq.top().first;
            j--;
			// s2=48+l+1;
			// s3+=48+1+'\t';
            // s1+='P'+s2+'\t';
            if (j>0)
            {
                pq.pop();
                pq.push(make_pair(j,l));
                count++;
            }
            else if (j==0)
            {
                pq.pop();
                count++;
                ct[l]=count;
				atc[l]=max+1;
				min=max+1;
				if (n1!=n){
				for ( i=0;i<n;i++)
				{
					if (atc[i]<min)
					{
						min=atc[i];
					}
				}
			}
			if(min-count>0)
				count+=(min-count);
            }
            if(n1<=n){
            for (i=0;i<n;i++)
            {
                if (at[i]<=count && atcc[i]==false)
                {
                    pq.push(make_pair(bt[i],i));
                    atcc[i]=true;
                    n1++;
                }
            }
            }
            else break;
    }
	float sumta=0,sumwt=0;
	for( i=0;i<n;i++)
	{
		ta[i]=ct[i]-at[i];
		wt[i]=ta[i]-bt[i];
		sumta+=ta[i];
		sumwt+=wt[i];
	}
	float avgtat=sumta/n;
	float avgwt=sumwt/n;
    // cout<<s1<<endl;
	// cout<<s3<<endl;
	cout<<endl<<"Pno."<<"\t"<<"AT"<<"\t"<<"BT"<<"\t"<<"CT"<<"\t"<<"TAT"<<"\t"<<"WT"<<endl;
	for( i=0;i<n;i++)
	{
		cout<<i+1<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<ct[i]<<"\t"<<ta[i]<<"\t"<<wt[i]<<"\t"<<endl;
	}
	cout<<"Average Turn Around Time : "<<avgtat<<endl;
	cout<<"Average Waiting Time :"<<avgwt<<endl;
	delete []at;
	delete []bt;
	delete []ta;
	delete []wt;
	delete []ct;
}