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
	int number,choice,start,count=0;
	bool flag=true;
	char buffer[30];
	inPtr=fopen("./wl.txt","r");
	outPtr=fopen("./res.txt","a");
	rePtr=fopen("./rev.txt","a");
	loPtr=fopen("./log.txt","r+");
	start=initialize(loPtr);
	for(int i=0;i<start;i++)fgets(buffer,sizeof(buffer),inPtr);
	cout<<"You have already recited "<<start<<" words"<<endl;
	count=start;
	if (inPtr == NULL)
	{
		cout<<"ERROR!"<<endl;
	}
	else
	{
		cout<<"How much do you want?"<<endl;
		cin>>number;
		while(flag)
		{
			system("clear");
			for (int i=0;i<number && !feof(inPtr);i++)
			{
				cout<<"You have already recited "<<count<<" words"<<endl;
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
				count++;
				fflush(inPtr);
				system("clear");
			}
			
			cout<<"Do you want to continue?"<<endl
				<<"1 For YES,2 For NO"<<endl;
			cin>>choice;
			if(choice==2)flag=false;
		}
		fseek(loPtr,0,SEEK_SET);
		fprintf(loPtr, "%d", count);
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
	num=atoi(ch);
	return num;
	
} 