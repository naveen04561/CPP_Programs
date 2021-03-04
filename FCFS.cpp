#include<iostream>
using namespace std;

int main()
{
	int n;
	cout<<"Enter the number of processes : ";
	cin>>n;
	float *at=new float[n];
	float *bt=new float[n];
	for(int i=0;i<n;i++)
	{
		cout<<"Enter the values of arrival time and burst time of the "<<i+1<<" process"<<endl;
		cin>>at[i]>>bt[i];
	}
	float *ct=new float[n];
	float *ta=new float[n];
	float *wt=new float[n];
	ct[0]=at[0]+bt[0];
	for(int i=1;i<n;i++)
	{
		if (ct[i-1]>at[i])
			ct[i]=ct[i-1]+bt[i];
		else
		{
			float s=at[i]-ct[i-1];
			ct[i]=ct[i-1]+bt[i]+s;
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
	// for(float i=0;i<38;i++)
	// cout<<"_";
	// cout<<endl;
	// for(int i=0;i<n;i++)
	// cout<<"| P"<<i+1<<"\t";
	// cout<<endl;
	// cout<<"| P1 \t | P2 \t | P3 \t | P4 \t | P5 |"<<endl;
	for(int i=0;i<n;i++)
	{
		if (ct[i-1]>at[i])
		cout<<"|"<<at[i]<<" P"<<i+1<<" "<<ct[i];
	}
	// cout<<" |";
	// cout<<endl;
	// for(float i=0;i<38;i++)
	// cout<<"_";
	cout<<endl<<endl<<"Pno."<<"\t"<<"AT"<<"\t"<<"BT"<<"\t"<<"CT"<<"\t"<<"TAT"<<"\t"<<"WT"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<i+1<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<ct[i]<<"\t"<<ta[i]<<"\t"<<wt[i]<<"\t"<<endl;
	}
	cout<<"Average Turn Around Time : "<<avgtat<<endl;
	cout<<"Average Waiting Time :"<<avgwt<<endl;
}
