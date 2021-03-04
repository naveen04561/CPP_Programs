#include<bits/stdc++.h>
using namespace std;

int main()
{
    int numberOfResoures,numberOfProcess,i=0,j=0;
    cout<<"Enter the number of resources and number of numberOfProcess: ";
    cin>>numberOfResoures>>numberOfProcess;
    int allocated[numberOfProcess][numberOfResoures],maxNeed[numberOfProcess][numberOfResoures],
    available[numberOfResoures],maxAvailable[numberOfResoures],remainingNeed[numberOfProcess][numberOfResoures];
    cout<<"Enter the availability of each resource: ";
    for(i=0;i<numberOfResoures;i++)
    {
        cin>>available[i];
    }
    for(i=0;i<numberOfProcess;i++)
    {
        cout<<"Enter the amount allocated to each resource to the process "<<i+1<<": ";
        for(j=0;j<numberOfResoures;j++)
        {
            cin>>allocated[i][j];
        }
    }
    for(i=0;i<numberOfProcess;i++)
    {
        cout<<"Enter the max need of each resource for the process "<<i+1<<": ";
        for(j=0;j<numberOfResoures;j++)
        {
            cin>>maxNeed[i][j];
        }
    }
    for(i=0;i<numberOfProcess;i++)
    {
        for(j=0;j<numberOfResoures;j++)
        {
            remainingNeed[i][j] = maxNeed[i][j] - allocated[i][j];
        }
    }
    int running[numberOfProcess];
    int counter=0,flag=0;
    for (i = 0; i < numberOfProcess; i++) 
	{
        running[i] = 1;
        counter++;
    }
    vector<int> safeSequence;
    int exec;
    while (counter != 0) 
	{
        int safe = 0;
        for (i = 0; i < numberOfProcess; i++) 
		{
            if (running[i]) 
			{
                exec = 1;
                for (j = 0; j < numberOfResoures; j++) 
				{
                    if (maxNeed[i][j] - allocated[i][j] > available[j]) 
					{
                        exec = 0;
                        break;
                    }
                }
                if (exec) 
				{
                    running[i] = 0;
                    counter--;
                    safe = 1;
                    safeSequence.push_back(i+1);
 
                    for (j = 0; j < numberOfResoures; j++) 
					{
                        available[j] += allocated[i][j];
                    }
			        break;
                }
            }
        }
        if (!safe) 
		{
            printf("\nThe System is in unsafe state.\n");
            break;
        } 
		else 
		{
            flag=1;
        }
    }
    if(flag=1)
    {
        cout<<"\nSystem is in safe state.\nThe Safe Sequence is: ";
        for(vector<int>::iterator itr=safeSequence.begin();itr<safeSequence.end();itr++)
        {
            cout<<"P"<<*itr<<"  ";
        }
        cout<<endl<<"Process\t\tAllocated\tMax Need\tRemaining Need\n";
        cout<<"\t\t";
        for(i=0;i<numberOfResoures;i++)
        { 
            for(j=0;j<numberOfResoures;j++)
            {
                cout<<"R"<<j+1<<"  ";
            }
            cout<<"\t";
        }
        cout<<endl;
        for(i=0;i<numberOfProcess;i++)
        {
            cout<<"P"<<i+1<<"\t\t";
            for(j=0;j<numberOfResoures;j++)
            {
                cout<<allocated[i][j]<<"   ";
            }
            cout<<"\t";
            for(j=0;j<numberOfResoures;j++)
            {
                cout<<maxNeed[i][j]<<"   ";
            }
            cout<<"\t";
            for(j=0;j<numberOfResoures;j++)
            {
                cout<<remainingNeed[i][j]<<"   ";
            }
            cout<<endl;
        }
    }
}


