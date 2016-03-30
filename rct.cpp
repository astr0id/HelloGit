#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
using namespace std;
int initialize(FILE *);
int main()
{
	FILE * inPtr;
	FILE * outPtr;
	FILE * rePtr;
	FILE * loPtr;
	int number,choice,start;
	char buffer[30];
	inPtr=fopen("./wl.txt","r");
	outPtr=fopen("./res.txt","a");
	rePtr=fopen("./rev.txt","a");
	loPtr=fopen("./log.txt","r+");
	start=initialize(loPtr);
	for(int i=0;i<start;i++)fgets(buffer,sizeof(buffer),inPtr);
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
	fclose(loPtr);
	return 0;
}
int initialize(FILE * logP)
{
	char ch[20];
	int num;
	fgets(ch,sizeof(ch),logP);
	cout<<"You have already recited "<<ch<<" words"<<endl;
	num=atoi(ch);
	return num;
	
} 