#include<stdio.h>
#define A 16
#define B 7
#define C 8
#define D 1
#define E 1
#define F 2
#define G 3
int getp(int n){
	int i,sum=0,flag1=0,flag2=0;
	char ch[10];
	for(i=1;i<=n;i++){
		scanf("%s",ch);
		switch(ch[0]){
			case 'A':sum+=A;break;
			case 'B':sum+=B;flag1=1;break;
			case 'C':sum+=C;flag2=1;break;
			case 'D':sum+=D;break;
			case 'E':sum+=E;break;
			case 'F':sum+=F;break;
			case 'G':sum+=G;break;
		}
	}
	
	if((flag1==0 || flag2==0)&&sum>1)sum--;
	return sum;
}
int main(){
	int red,blc,i,T,m;
	scanf("%d",&T);
	for(i=1;i<=T;i++){
		scanf("%d",&m);
		red=getp(m);
		scanf("%d",&m);
		blc=getp(m);
		if(red>blc)printf("red\n");
		if(red==blc)printf("tie\n");
		if(red<blc)printf("black\n");
	}
	return 0;
}

