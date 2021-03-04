// #include <iostream>
// using namespace std;

// int main()
// {
//     int a[4], b[4], r[3], s[3], i, q[3];
//     cout<<"Enter 4 bit data word : ";
//     for (i = 3; i >= 0; i--)
//     {
//         cin>>a[i];
//     }
//     r[0] = (a[2] + a[1] + a[0]) % 2;
//     r[1] = (a[2] + a[1] + a[3]) % 2;
//     r[2] = (a[0] + a[1] + a[3]) % 2;
//     printf("\nThe 7bit hamming code word : ");
//     for (i = 3; i >= 0; i--)
//     {
//         cout<<a[i]<<" ";
//     }
//     for (i = 2; i >= 0; i--)
//     {
//         cout<<r[i]<<" ";
//     }
//     printf("\nEnter the 4bit recieved word: ");
//     for (i = 3; i >= 0; i--)
//         cin>>b[i];
//     s[0] = (b[2] + b[1] + b[0] + r[0]) % 2;
//     s[1] = (b[3] + b[2] + b[1] + r[1]) % 2;
//     s[2] = (b[0] + b[1] + b[3] + r[2]) % 2;
//     // printf("\nsyndrome is: \n");
//     // for (i = 2; i >= 0; i--)
//     // {
//     //     printf("%d", s[i]);
//     // }
//     if ((s[2] == 0) && (s[1] == 0) && (s[0] == 0))
//         printf("\nRECIEVED WORD IS ERROR FREE\n");
//     else
//         printf("There is error in the message.");
//     if ((s[2] == 1) && (s[1] == 0) && (s[0] == 1))
//         printf("\nError bit is 1st bit from right.\n");
//     if ((s[2] == 1) && (s[1] == 1) && (s[0] == 1))
//         printf("\nError bit is 2nd bit from right.\n");
//     if ((s[2] == 0) && (s[1] == 1) && (s[0] == 1))
//         printf("\nError bit is 3rd bit from right.\n");
//     if ((s[2] == 1) && (s[1] == 1) && (s[0] == 0))
//         printf("\nError bit is 4th bit from right.\n");
//     return 0;
// }

// #include<iostream>

// using namespace std;

// int main() {
//     int data[10];
//     int redata[10],c,c1,c2,c3,i;

//     cout<<"Enter 4 bits of data one by one : ";
//     cin>>data[0];
//     cin>>data[1];
//     cin>>data[2];
//     cin>>data[4];

//     //Calculation of even parity
//     data[6]=data[0]^data[2]^data[4];
// 	data[5]=data[0]^data[1]^data[4];
// 	data[3]=data[0]^data[1]^data[2];

// 	cout<<"\nEncoded data is : ";
// 	for(i=0;i<7;i++)
//         cout<<data[i]<<" ";

// 	cout<<"\n\nEnter received data bits one by one : ";
//     for(i=0;i<7;i++)
//         cin>>redata[i];

//     c1=redata[6]^redata[4]^redata[2]^redata[0];
// 	c2=redata[5]^redata[4]^redata[1]^redata[0];
// 	c3=redata[3]^redata[2]^redata[1]^redata[0];
// 	c=c3*4+c2*2+c1 ;

//     if(c==0) {
// 		cout<<"\nNo error while transmission of data.\n";
//     }
// 	else {
//         cout<<"\nData received : ";
//         for(i=0;i<7;i++)
//         	cout<<redata[i]<<" ";
//         cout<<"\nEven Parity is used.";
// 		cout<<"\nError on position "<<c;

// 		// cout<<"\nData sent : ";
// 		// for(i=0;i<7;i++)
//         // 	cout<<data[i];

// 		cout<<"\nCorrect message is : ";

// 		//if errorneous bit is 0 we complement it else vice versa
// 		if(redata[7-c]==0)
// 			redata[7-c]=1;
//         else
// 		 	redata[7-c]=0;
// 		for (i=0;i<7;i++) {
// 			cout<<redata[i]<<" ";
// 		}
// 	}
// 	return 0;
// }


#include<bits/stdc++.h>
using namespace std;

class Hamming

{
    string message;

    int codeword[50], temp[50];
    int n, check;
    char parity;

public:
    Hamming()
    {
        parity = 'E';
        message = "";
        n = check = 0;
        for (int i = 0; i < 50; i++)
        {
            temp[i] = codeword[i] = 0;
        }
    }

    void generate()
    {
        do
        {
            cout << "Enter the message in binary : ";
            cin >> message;
        } while (message.find_first_not_of("01") != string::npos);
        n = message.size();
        cout << "Odd(O)/Even(E) Parity ? ";
        cin >> parity;
        for (unsigned int i = 0; i < message.size(); i++)
        {
            if (message[i] == '1')
                temp[i + 1] = 1;
            else
                temp[i + 1] = 0;
        }
        computeCode();
    }
    void computeCode()
    {
        check = findr();
        cout << "Number of Check Bits : " << check << endl;
        cout << "Number of Bits in Codeword : " << n + check << endl;
        for (int i = (n + check), j = n; i > 0; i--)
        {
            if ((i & (i - 1)) != 0)
                codeword[i] = temp[j--];
            else
                codeword[i] = setParity(i);
        }
        cout << "Parity Bits - ";
        for (int i = 0; i < check; i++)
            cout << "P" << pow(2, i) << " : " << codeword[(int)pow(2, i)] << "\t";
        cout << endl;
        cout << "Codeword :" << endl;
        for (int i = 1; i <= (n + check); i++)
            cout << codeword[i] << " ";
        cout << endl;
    }
    int findr()
    {
        for (int i = 1;; i++)
        {
            if (n + i + 1 <= pow(2, i))
                return i;
        }
    }
    int setParity(int x)
    {
        bool flag = true;
        int bit;
        if (x == 1)
        {
            bit = codeword[x + 2];
            for (int j = x + 3; j <= (n + check); j++)
            {
                if (j % 2)
                {
                    bit ^= codeword[j];
                }
            }
        }
        else
        {
            bit = codeword[x + 1];
            for (int i = x; i <= (n + check); i++)
            {
                if (flag)
                {
                    if (i == x || i == x + 1)
                        bit = codeword[x + 1];
                    else
                        bit ^= codeword[i];
                }
                if ((i + 1) % x == 0)
                    flag = !flag;
            }
        }
        if (parity == 'O' || parity == 'o')
            return !bit;
        else
            return bit;
    }
    void correct()
    {
        do
        {
            cout << "Enter the received codeword : ";
            cin >> message;
        } while (message.find_first_not_of("01") != string::npos);
        for (unsigned int i = 0; i < message.size(); i++)
        {
            if (message[i] == '1')
                codeword[i + 1] = 1;
            else
                codeword[i + 1] = 0;
        }
        detect();
    }
    void detect()
    {
        int position = 0;
        cout << "Parity Bits - ";
        for (int i = 0; i < check; i++)
        {
            bool flag = true;
            int x = pow(2, i);
            int bit = codeword[x];
            if (x == 1)
            {
                for (int j = x + 1; j <= (n + check); j++)
                {
                    if (j % 2)
                    {
                        bit ^= codeword[j];
                    }
                }
            }
            else
            {
                for (int k = x + 1; k <= (n + check); k++)
                {
                    if (flag)
                    {
                        bit ^= codeword[k];
                    }
                    if ((k + 1) % x == 0)
                        flag = !flag;
                }
            }
            cout << "P" << x << ": " << bit << "\t";
            if ((parity == 'E' || parity == 'e') && bit == 1)
                position += x;
            if ((parity == 'O' || parity == 'o') && bit == 0)
                position += x;
        }
        cout << endl
             << "Received Codeword :" << endl;
        for (int i = 1; i <= (n + check); i++)
            cout << codeword[i] << " ";
        cout << endl;
        if (position != 0)
        {
            cout << "Error at bit : " << position << endl;
            codeword[position] = !codeword[position];
            cout << "Corrected Codeword : " << endl;
            for (int i = 1; i <= (n + check); i++)
                cout << codeword[i] << " ";
            cout << endl;
        }
        else
            cout << "No Error in Received code." << endl;
        cout << "Received Message is : ";
        for (int i = 1; i <= (n + check); i++)
            if ((i & (i - 1)) != 0)
                cout << codeword[i] << " ";
        cout << endl;
    }
};

int main()
{
    char choice;
    do
    {
        Hamming a;
        cout << "At Sender's side : " << endl;
        a.generate();
        cout << endl
             << "At Receiver's Side : " << endl;
        a.correct();
        cout << endl
             << "Enter another code ? (Y/N) : ";
        cin >> choice;
        cout << endl;
    } while (choice == 'y' || choice == 'Y');
    return 0;
}