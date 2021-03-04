#include<iostream>
using namespace std;

int mutex=1,full=0,empty=3,x=0;

int wait(int s)
{
	return (--s);
}

int signal(int s)
{
	return(++s);
}
 
void producer()
{
    empty=wait(empty);
	mutex=wait(mutex);
    x++;
    cout<<"Producer produces item "<<x<<endl;
    mutex=signal(mutex);
	full=signal(full);
}
 
void consumer()
{
	full=wait(full);
    mutex=wait(mutex);
    cout<<"Consumer consumes item "<<x<<endl;
    x--;
	mutex=signal(mutex);
    empty=signal(empty);
}

int main()
{
	int n;
	cout<<("1.Produce an item\n2.Consume an item\n3.Exit");
	while(1)
	{
		cout<<"\nEnter your choice:";
		cin>>n;
		switch(n)
		{
			case 1:	if((mutex==1)&&(empty!=0))
						producer();
					else
						cout<<"Buffer is full!!";
					break;
			case 2:	if((mutex==1)&&(full!=0))
						consumer();
					else
						cout<<"Buffer is empty!!";
					break;
			case 3:
					exit(0);
					break;
        }
	}
	
	return 0;
}
// #include<stdio.h>
// #include<stdlib.h>
 
// int mutex=1,full=0,empty=3,x=0;
 
// int main()
// {
// 	int n;
// 	void producer();
// 	void consumer();
// 	int wait(int);
// 	int signal(int);
// 	printf("\n1.Producer\n2.Consumer\n3.Exit");
// 	while(1)
// 	{
// 		printf("\nEnter your choice:");
// 		scanf("%d",&n);
// 		switch(n)
// 		{
// 			case 1:	if((mutex==1)&&(empty!=0))
// 						producer();
// 					else
// 						printf("Buffer is full!!");
// 					break;
// 			case 2:	if((mutex==1)&&(full!=0))
// 						consumer();
// 					else
// 						printf("Buffer is empty!!");
// 					break;
// 			case 3:
// 					exit(0);
// 					break;
// 		}
// 	}
	
// 	return 0;
// }
 
// int wait(int s)
// {
// 	return (--s);
// }
 
// int signal(int s)
// {
// 	return(++s);
// }
 
// void producer()
// {
// 	mutex=wait(mutex);
// 	full=signal(full);
// 	empty=wait(empty);
// 	x++;
// 	printf("\nProducer produces the item %d",x);
// 	mutex=signal(mutex);
// }
 
// void consumer()
// {
// 	mutex=wait(mutex);
// 	full=wait(full);
// 	empty=signal(empty);
// 	printf("\nConsumer consumes item %d",x);
// 	x--;
// 	mutex=signal(mutex);
// }