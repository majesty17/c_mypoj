#include <stdio.h>
#include <stdlib.h>

int n;
int *num;
int **sum;
int i,j;
int maxb(int from,int to){
    int ret=0x80000000;
    int ii,jj;
    for(ii=from;ii<=to;ii++){
        for(jj=ii;jj<=to;jj++){
            ret=ret>sum[ii][jj]?ret:sum[ii][jj];
        }
    }
    return ret;
}
int main(){
    while(1){
        scanf("%d",&n);
        if(n==0)break;
        num=(int*)malloc(n*sizeof(int));
        sum=(int**)malloc(n*sizeof(int*));
        for(i=0;i<n;i++){
            scanf("%d",num+i);
        }
        for(i=0;i<n;i++){
            sum[i]=(int*)calloc(n,sizeof(int));
            sum[i][i]=num[i];
            for(j=i+1;j<n;j++){
                sum[i][j]=sum[i][j-1]+num[j];
            }
        }

        int max=0x80000000;
        for(i=0;i<n-1;i++){
            int tmp=maxb(0,i)+maxb(i+1,n-1);
            max=max>tmp?max:tmp;
        }
//        for(i=0;i<n;i++){
//            for(j=0;j<n;j++){
//                printf("%d\t",sum[i][j]);
//            }
//            printf("\n");
//        }
        printf("%d\n",max);
        for(i=0;i<n;i++)free(sum[i]);
        free(sum);
        free(num);
    }
}
