//
//  main.c
//  tyvj1001
//
//  Created by Lin Haoyu on 14/12/1.
//  Copyright (c) 2014年 Lin Haoyu. All rights reserved.
//

#include <stdio.h>

long long a[10001],n;

void getmax(int head){
    long long swap,flag,i,min=2147483647;
    for (i=head;i<=n;i++){
        if (a[i]<=min){
            min=a[i];
            flag=i;
        }
    }
    swap=a[head];
    a[head]=a[flag];
    a[flag]=swap;
}
int main(){
    int k,i;
    scanf("%lld %d",&n,&k);
    for (i=1;i<=n;i++)
        scanf("%lld",a[i]);
    for (i=1;i<=k;i++)
        getmax(i);
    printf("%lld",a[k]);
    return 0;
}