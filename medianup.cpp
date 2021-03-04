#include<bits/stdc++.h>
using namespace std;

double findMedian(multiset<int> m)
{
    int n = m.size();
    int v[n],i=0;
    for(int x: m)
    {
        v[i] = x;
        i++;
    }
    if(n%2 == 0)
    {
        return (v[n/2] + v[n/2 - 1])/2.0; 
    }
    else 
    {
        return double(v[n/2]);
    }
}

void median(vector<char> s,vector<int> X) {
    multiset<int> m;
    for(int i=0;i<s.size();i++)
    {
        if(s[i] == 'a')
        {
            m.insert(X[i]);
            cout<<findMedian(m)<<"\n";
        }
        else
        {
            if(m.find(X[i]) != m.end())
            {
                m.erase(X[i]);
                cout<<findMedian(m)<<"\n";
            }
            else
            {
                cout<<"Wrong!\n";
            }   
        }
    }
}
int main(void){

//Helpers for input and output

	int N;
	cin >> N;
	
	vector<char> s;
    vector<int> X;
	char temp;
    int tempint;
	for(int i = 0; i < N; i++){
		cin >> temp >> tempint;
        s.push_back(temp);
        X.push_back(tempint);
	}
	
	median(s,X);
	return 0;
}
