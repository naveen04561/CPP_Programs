#include <bits/stdc++.h>
using namespace std;

int main() 
{
	int t,n,i,j;
	cin>>t;
	while(t>0)
	{
	    cin>>n;
	    int a[n],profit=0,k=0;
	    for(i=0;i<n;i++)
	    cin>>a[i];
	    i=0,j=0;
	    int buy=a[0];
		int start=-1,end=-1;
		vector<int>v;
		while(i<n)
		{
			buy=a[i];
			start=i;
			for(j=i+1;j<n;j++)
			{
				if(buy<a[j])
				{
					k=j;
					end=j;
				}
				else
				{
					end=j-1;
					break;
				}
			}
			// if(end==j-1 && i==0){
			// 	cout<<"No Profit";
			// 	break;
			// }
			// else
			// {
			profit+=(a[k]-buy);
			i=k+1;
			cout<<"("<<start<<" "<<end<<") ";
		}
		cout<<"\n";
        t--;
	}
	return 0;
}