// #include <iostream>
// using namespace std;


// string text,key,rem;


// void crc()
// {
//     int i, j;
//     int keylen, textlen;
//     string temp;
//     temp += text;
//     keylen = key.length();
//     for (i = 0; i < keylen - 1; i++)
//         temp += '0';
//     textlen = temp.length();
//     // strncpy(rem, temp, keylen);
//     for(i = 0; i < keylen; i++)
//         rem[i] = temp[i];
//     while (i != textlen)
//     {
//         if (rem[0] == '0')
//         {
//             rem = &rem[1];
//             rem[keylen - 1] = temp[++i];
//             // rem[keylen] = '\0';
//             continue;
//         }
//         for (j = 0; j < keylen; j++)
//             rem[j] = ((rem[j] - '0') ^ (key[j] - '0')) + '0';
//     }
// }
// int main()
// {
//     int i;
//     int choice;
//     while (1)
//     {
        // printf("\n1.find crc\t2.check crc\t3.exit crc\nyour choice\t");
        // scanf("%d", &choice);
//         switch (choice)
//         {
//         case 1:
//             printf("Enter the input string : ");
//             cin>>text;
//             printf("Enter the key : ");
//             cin>>key;
//             crc();
//             text += rem;
//             cout<<"the transmitted message is : "<<text<<"\n";
//             break;
//         case 2:
//             cout<<"Enter the input string : ";
//             cin>>text;
//             cout<<"Enter the key : ";
//             cin>>key;
//             crc();
//             for (i = 0; i < key.length() - 1; i++)
//                 if (rem[i] == '1')
//                     break;
//             if (i == key.length() - 1)
//                 cout<<"There is no error in the message\n";
//             else
//                 cout<<"There is error in the message\n";
//             break;
//         case 3:
//             exit(0);
//         }
//     }
// }

#include<iostream>

using namespace std;

string crcheck(string encoded,string crc)
{
	int crclen = crc.length();
	for (int i=0;i<=(encoded.length()-crclen);)
	{
		for(int j=0;j<crclen;j++)
		{
			encoded[i+j] = encoded[i+j] == crc[j] ? '0' : '1' ;			//if encoded bit and crc bit are same , then replace it with zero
		}
	    for(;i<encoded.length()&&encoded[i] != '1';i++) ;
	
	}
	return encoded;
}

int main()
{
    int option,crclen,datalen,i,flag;
    string data , crc , encoded = "",msg;
    while(1)
    {
        cout<<("1.Sender\t2.Receiver\t3.Exit\nEnter your choice : ");
        cin>>option;
        switch (option)
        {
            case 1:
                cout<<"Enter Data bits: ";								
                cin>>data;
                cout<<"Enter Generator: ";
                cin>>crc;
                encoded += data;
                datalen = data.length();
                crclen = crc.length();
                
                for(int i=1 ; i <= (crclen - 1) ; i++)
                    encoded += '0';
                
                encoded = crcheck(encoded , crc);
                
                // cout<<"Checksum generated is: ";
                // cout<<encoded.substr(encoded.length() - crclen + 1)<<endl;
                cout<<"Message to be Transmitted over network: ";
                cout<<data + encoded.substr(encoded.length() - crclen + 1)<<endl;    					
                break;
            
            case 2:
                cout<<"Enter the message recieved : ";
                cin>>msg;
                cout<<"Enter Generator: ";
                cin>>crc;
                crclen = crc.length();
                msg = crcheck(msg,crc);
                flag = 0;
                for( char i : msg.substr(msg.length() - crclen + 1))
                    if( i != '0' )
                        {	
                            cout<<"There is error in the message"<<endl;
                            flag = 1;
                        }
                if(flag == 0)
                cout<<"There is no error in the message"<<endl;	
                break;
            
            case 3:
                exit(0);
        }
    }
	return 0;
}