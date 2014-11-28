//
//  main.c
//  POJ3299
//
//  Created by Lin Haoyu on 14/11/28.
//  Copyright (c) 2014年 Lin Haoyu. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int main(){
    double temper,dew,humidex;
    char ch;
    int i;
    while(1){
        temper=dew=humidex=101;
        for(i=1;i<=2;i++){
            ch=getchar();
            if(ch=='E')return 0;
            if(ch=='T')scanf(" %lf",&temper);
            if(ch=='D')scanf(" %lf",&dew);
            if(ch=='H')scanf(" %lf",&humidex);
            getchar();
        }
        if(temper==101 && dew==101 && humidex==101)return 0;
        if(humidex==101)
            humidex=temper+(0.5555)*(6.11*exp(5417.7530*((1/273.16)-(1/(dew+273.16))))-10);
        if(dew==101)
            dew=1/((1/273.16)-((log((((humidex-temper)/0.5555)+10.0)/6.11))/5417.7530))-273.16;
        if(temper==101)
            temper=humidex-0.5555*(6.11*exp(5417.7530*(1/273.16-1/(dew+273.16)))-10);
        
        printf("T %.1lf D %.1lf H %.1lf\n",temper,dew,humidex);
    }
    return 0;
}