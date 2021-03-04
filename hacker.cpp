// // #include<iostream>
// // #include<string>
// // using namespace std;


// // // /*
// // //  * Complete the timeConversion function below.
// // //  */
// // // string timeConversion(string s) {
// // //     int a=s.length();
// // //     string s1;
// // //     if (s[a-1]=='P')
// // //     {
// // //         if (s[0]=='0'&&(s[1]=='1'||s[1]=='2'||s[1]=='3'||s[1]=='4'||s[1]=='5'||s[1]=='6'||s[1]=='7'))
// // //             {
// // //                 s[0]+=1;
// // //                 switch(s[1])
// // //                 {
// // //                     case '1':
// // //                     s[1]+=2;
// // //                     break;
// // //                     case '2':
// // //                     s[1]+=2;
// // //                     break;
// // //                     case '3':
// // //                     s[1]+=2;
// // //                     break;
// // //                     case '4':
// // //                     s[1]+=2;
// // //                     break;
// // //                     case '5':
// // //                     s[1]+=2;
// // //                     break;
// // //                     case '6':
// // //                     s[1]+=2;
// // //                     break;
// // //                     case '7':
// // //                     s[1]+=2;
// // //                     break;
// // //                 }
// // //             }
// // //         else if (s[0]=='0'&&(s[1]=='8'||'9')){
// // //             s[0]='2';
// // //             if (s[1]=='8')
// // //                 s[1]='0';
// // //             else if (s[1]=='9')
// // //                 s[1]='1';
// // //         }
// // //         else if (s[0]=='1'&&(s[1]==0||s[1]=='1')){
// // //             s[0]='2';
// // //             if (s[1]=='0')
// // //                 s[1]='2';
// // //             else if (s[1]=='1')
// // //                 s[1]='3';
// // //         }
// // //     }
// // //     else if (s[a-2]=='A'){
// // //         if (s[0]=='1'&&s[1]=='2'){
// // //             s[0]='0';
// // //             s[1]='0';
// // //         }
// // //     }
// // //     for (int i=0;i<(a-2);i++)
// // //     {
// // //         s1+=s[i];
// // //     }
// // //     return s1;
// // // }


// // // int main()
// // // {
// // //     string s;
// // //     cin>>s;
// // //     cout<<(timeConversion(s));

// // //     return 0;
// // // }

// // #include <bits/stdc++.h>
// // using namespace std;

// // int main() {
// //     int T;
// //     cin>>T;
// //     int j,i;
// //     for(i=0;i<T;i++)
// //     {
// //         long N,M;
// //         cin>>N>>M;
// //         long af[N],ap[N],re[M],re1[M];
// //         for(j=0;j<N;j++)
// //         {
// //             cin>>af[j];
// //         }
// //         for(j=0;j<N;j++)
// //         {
// //             cin>>ap[j];
// //         }
// //         for(j=0;j<M;j++){
// //             re[j]=0;
// //             re1[j]=-1;
// //         }
// //         for(j=0;j<N;j++)
// //         {
// //             re[af[j]-1]+=ap[j];
// //             re1[af[j]-1]=0;
// //         }
// //         priority_queue <long,vector<long>,greater<long> > q;
// //         for (j=0;j<M;j++)
// //         {
// //             if (re1[j]!=-1)
// //             {
// //                 q.push(re[j]);
// //             }
// //         }
// //         cout<<q.top();
// //     }
// // 	return 0;
// // }
// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     long T;
//     cin>>T;
//     long j,i;
//     for(i=0;i<T;i++)
//     {
//         long N,M;
//         cin>>N>>M;
//         long fruitType[N],cost[N],result[M],resultc[M];
//         for(j=0;j<N;j++)
//         {
//             cin>>fruitType[j];
//         }
//         for(j=0;j<N;j++)
//         {
//             cin>>cost[j];
//         }
//         for(j=0;j<M;j++){
//             result[j]=0;
//             resultc[j]=-1;
//         }
//         for(j=0;j<N;j++)
//         {
//             result[fruitType[j]-1]+=cost[j];
//             resultc[fruitType[j]-1]+=1;
//         }
//         vector<long> v ;
//         for (j=0;j<M;j++)
//         {
//             if (resultc[j]!=-1)
//             {
//                 v.push_back(result[j]);
//             }
//         }
//         sort(v.begin(), v.end());
//         cout<<(*(v.begin()));
//     }  
// 	return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;

// bool getParity(long n) 
// { 
//     bool parity = 0; 
//     while (n) 
//     { 
//         parity = !parity; 
//         n = n & (n - 1); 
//     }      
//     return parity; 
// }

// int main()
// {
//     long T=0,i=0,j=0;
//     scanf("%ld",&T);
//     for (i=0;i<T;i++)
//     {
//         long N=0,Q=0,P=0,Ans=0,Even=0,Odd=0;
//         scanf("%ld %ld",&N,&Q);
//         long s[N];
//         for (j=0;j<N;j++)
//         {
//             scanf("%ld",&s[j]);
//         }
//         for (j=0;j<N;j++)
//         {
//             if (getParity(s[j]))
//             {
//                 Odd+=1;
//             }
//             else 
//             {
//                 Even+=1;
//             }
//         }
//         for (long k=0;k<Q;k++){
//             scanf("%ld",&P);
//             long pp = getParity(P);
//             if (pp)
//             {
//                 printf("%ld %ld\n",Odd,Even);
//             }
//             else
//             {
//                 printf("%ld %ld\n",Even,Odd);
//             }
            
//         }
//     }
// }




#include<iostream>
using namespace std;

typedef pair<int,int> pi;
int main()
{
    long T=0,i=0;
    cin>>T;
    long numberOfMoves=19;
        pi ar[]={ 
                    make_pair(1,1),make_pair(8,8),make_pair(7,7),make_pair(6,8),make_pair(1,3),make_pair(2,4),
                    make_pair(1,5),make_pair(4,8),make_pair(3,7),make_pair(2,8),make_pair(1,7),make_pair(7,1),
                    make_pair(8,2),make_pair(7,3),make_pair(5,1),make_pair(8,4),make_pair(7,5),make_pair(8,6),
                    make_pair(3,1)
                };
    while(T>0)
    {
        long r=0,c=0;
        cin>>r>>c;
        pi p = make_pair(r,c);
            if (p==make_pair(1,1))
            {
                cout<<numberOfMoves-1<<"\n";
                for(i=1;i<19;i++)
                {
                    cout<<ar[i].first<<" "<<ar[i].second<<"\n";
                }
            }
            else if (p == make_pair(1,3) || p == make_pair(3,1))
            {
                cout<<numberOfMoves+1<<"\n";
                cout<<"2 2"<<"\n";
                for(i=0;i<19;i++)
                {
                    cout<<ar[i].first<<" "<<ar[i].second<<"\n";
                }
            }
            else if (p == make_pair(2,4) || p==make_pair(4,2) || p==make_pair(1,5) || p==make_pair(5,1))
            {
                cout<<numberOfMoves+1<<"\n";
                cout<<"3 3"<<"\n";
                for(i=0;i<19;i++)
                {
                    cout<<ar[i].first<<" "<<ar[i].second<<"\n";
                }
            }
            else if (p==make_pair(3,5) || p==make_pair(2,6) || p==make_pair(1,7) || p==make_pair(7,1) || p==make_pair(6,2) || p==make_pair(5,3))
            {
                cout<<numberOfMoves+1<<"\n";
                cout<<"4 4"<<"\n";
                for(i=0;i<19;i++)
                {
                    cout<<ar[i].first<<" "<<ar[i].second<<"\n";
                }
            }
            else if (p == make_pair(2,8) || p==make_pair(3,7) || p==make_pair(4,6) || p==make_pair(6,4) || p==make_pair(7,3) || p==make_pair(8,2))
            {
                cout<<numberOfMoves+1<<"\n";
                cout<<"5 5"<<"\n";
                for(i=0;i<19;i++)
                {
                    cout<<ar[i].first<<" "<<ar[i].second<<"\n";
                }
            }
            else if (p==make_pair(4,8) || p==make_pair(5,7) || p==make_pair(7,5) || p==make_pair(8,4))
            {
                cout<<numberOfMoves+1<<"\n";
                cout<<"6 6"<<"\n";
                for(i=0;i<19;i++)
                {
                    cout<<ar[i].first<<" "<<ar[i].second<<"\n";
                }
            }
            else if (p==make_pair(6,8) || p==make_pair(8,6))
            {
                cout<<numberOfMoves+1<<"\n";
                cout<<"7 7"<<"\n";
                for(i=0;i<19;i++)
                {
                    cout<<ar[i].first<<" "<<ar[i].second<<"\n";
                }
            }
            else if (p==make_pair(2,2) || p==make_pair(3,3) || p==make_pair(4,4) || p==make_pair(5,5) || p==make_pair(6,6) || p==make_pair(7,7))
            {
                cout<<numberOfMoves<<"\n";
                for(i=0;i<19;i++)
                {
                    cout<<ar[i].first<<" "<<ar[i].second<<"\n";
                }
            }
            else if (p==make_pair(8,8))
            {
                cout<<numberOfMoves-1<<"\n";
                for(i=0;i<19;i++)
                {
                    if (i!=1)
                    cout<<ar[i].first<<" "<<ar[i].second<<"\n";
                }
            }
        T--;
    }
}


#include<bits/stdc++.h>
using namespace std;

int getLength(long long value) {
	int counter = 0;
	while (value != 0) {
		counter++;
		value /= 10;
	}
	return counter;
}

long long multiply(long long x, long long y) {
	int xLength = getLength(x);
	int yLength = getLength(y);

	// the bigger of the two lengths
	int N = (int)(fmax(xLength, yLength));

	// if the max length is small it's faster to just flat out multiply the two nums
	if (N < 10)
		return x * y;

	//max length divided and rounded up
	N = (N/2) + (N%2);

	long long multiplier = pow(10, N);

	long long b = x/multiplier;
	long long a = x - (b * multiplier);
	long long d = y / multiplier;
	long long c = y - (d * N);

	long long z0 = multiply(a,c);
	long long z1 = multiply(a + b, c + d);
	long long z2 = multiply(b, d);


    return z0 + ((z1 - z0 - z2) * multiplier) + (z2 * (long long)(pow(10, 2 * N)));

}

int main() {
	long long a = 24;
	long long b = 23;
	cout << multiply(a,b) << endl;
	return 0;
}




