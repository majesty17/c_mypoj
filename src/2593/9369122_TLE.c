#include <stdio.h>
#include <stdlib.h>

int n;
int *num;

int i,j;
int maxb(int from,int to){
    int max=0,sum=0;
    int i;
    for(i=from;i<=to;i++){
        sum+=num[i];
        if(sum<0)sum=0;
        if(sum>max)max=sum;
    }
    return max;
}
int main(){
    while(1){
        scanf("%d",&n);
        if(n==0)break;
        num=(int*)malloc(n*sizeof(int));

        for(i=0;i<n;i++){
            scanf("%d",num+i);
        }


        int max=0x80000000;
        for(i=0;i<n-1;i++){
            int tmp=maxb(0,i)+maxb(i+1,n-1);
            max=max>tmp?max:tmp;
        }
        printf("%d\n",max);
        free(num);
    }
}
