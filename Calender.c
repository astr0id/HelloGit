#include<stdio.h>
int passyear(int year){
	 if((year%4==0 && year%100!=0) || year%400==0){
	 	return 366;
	 }else{
	 	return 365;
	 }
}
int daycount(int year,int month){
	int i,day=0;
	for(i=1;i<year;i++)day+=passyear(i);
	for(i=1;i<=month-1;i++)day+=monthday(year,i);
	return day;
}
int monthday(int year,int month){
	if(passyear(year)==366 && month==2)return 29;
	if(month==2)return 28;
	switch(month){
		case 1:case 3:case 5:case 7:case 8:case 10:
		case 12:return 31;break;
		case 4:case 6:case 9:
		case 11:return 30;break;
	}
}

void printcal(int year,int month){
	int daytotal=0,count=0;
	int i,week;
	printf("\t\t\t%d-%d\n",year,month);
	printf("Sun\tMon\tTue\tWed\tThu\tFri\tSat\n");
	daytotal=daycount(year,month);
	daytotal++;
	week=daytotal % 7;
	if(week==6)week=0;
	for(i=0;i<week;i++){
		printf("\t");
		count++;
	}
	for(i=1;i<=monthday(year,month);i++){
		if(count==6){
			printf("%d\n",i);
			count=0;
		}else{
			printf("%d\t",i);
			count++;	
		}
		
	}
}
int main(){
	int year,month;
	scanf("%d %d",&year,&month);
	printcal(year,month);
	return 0;
}
