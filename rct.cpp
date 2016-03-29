#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
using namespace std;
int main()
{
	FILE * inPtr;
	FILE * outPtr;
	FILE * rePtr;
	int number,choice;
	char buffer[30];
	inPtr=fopen("./wl.txt","r");
	outPtr=fopen("./res.txt","a");
	rePtr=fopen("./rev.txt","a");

	if (inPtr == NULL)
	{
		cout<<"ERROR!"<<endl;
	}
	else
	{
		cout<<"How much do you want?"<<endl;
		cin>>number;
		for (int i=0;i<number && !feof(inPtr);i++)
		{
			fgets(buffer,sizeof(buffer),inPtr);
			cout<<buffer<<endl<<endl
			<<"1 for Aboslute, 2 for Blurly, 3 for No Idea"
			<<endl<<endl;
			cin>>choice;
			switch(choice)
			{
				case 1:
					break;
				case 2:
					fputs(buffer,rePtr);
					break;
				case 3:
					fputs(buffer,outPtr);
					break;
				default:
					break;
			}
			fflush(inPtr);
			system("clear");
		}
	}
	fclose(inPtr);
	fclose(outPtr);
	fclose(rePtr);
	return 0;

}