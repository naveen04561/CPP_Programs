#include <iostream>
using namespace std;

int main() {
	int t,n,i,j;
	cin>>t;
	while(t>0)
	{
	    cin>>n;
	    int a[n];
	    for(i=0;i<n;i++)
	        cin>>a[i];
		int max_sum=a[0],curr_sum=a[0];
		for(i=1;i<n;i++)
		{
			curr_sum=max(a[i],a[i]+curr_sum);
			max_sum=max(curr_sum,max_sum);
		}
		cout<<max_sum<<endl;
		t--;
	}
	return 0;
}