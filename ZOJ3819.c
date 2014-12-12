#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main(){
	int t,i;  
    int n, m;  
    int minn, maxx;  
    scanf("%d",&t);  
    while(t--)  
    {  
        scanf("%d %d",&n,&m);  
        double sum1=0, sum2=0;  
        int a;  
        for(i=0;i<n-1;i++)  
        {  
            scanf("%d",&a);  
            sum1+=a;  
        }  
        for(i=0; i<m;i++)  
        {  
            scanf("%d",&a);  
            sum2+=a;  
        }  
        double avg1=(sum1/(n-1.0));  
        double avg2=sum2/(m*1.0);  
        if((int)avg1==avg1)  {
        	maxx=(int)avg1-1;
		}else{
			maxx=(int)avg1;  
		} 
        minn=(int)avg2+1;  
        printf("%d %d\n",minn,maxx);  
    }  
    return 0;  
}
