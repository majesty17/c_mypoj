#include <stdio.h>
#include <string.h>
#include <math.h>
__int64 limit=1000000000000000000LL;
int n,k;
__int64 num[2][101][1001]={0,};
void init(){
	int i,j,k;
	for(i=1;i<=100;i++){
		for(j=1;j<=1000;j++){
			if(i==1){
				num[0][i][j]=1;
				continue;
			}
			else if(j==1){
				num[0][i][j]=1;
				continue;
			}

			if(i>j){
				num[0][i][j]=num[0][i-1][j];
				num[1][i][j]=num[1][i-1][j];
			}
			else if(i==j){
				num[0][i][j]=num[0][i-1][j]+1;
				num[1][i][j]=num[1][i-1][j];
				if(num[0][i][j]>=limit){
					num[0][i][j]-=limit;
					num[1][i][j]++;
				}
			}
			else{
				//先加上上面的
				num[0][i][j]=num[0][i-1][j];
				num[1][i][j]=num[1][i-1][j];

				for(k=1;k<=j/i;k++){
					num[0][i][j]+=num[0][i-1][j-i*k];
					num[1][i][j]+=num[1][i-1][j-i*k];
					if(num[0][i][j]>=limit){
						num[0][i][j]-=limit;
						num[1][i][j]++;
					}
				}
				if(j%i==0){
					num[0][i][j]+=1;
					if(num[0][i][j]>=limit){
						num[0][i][j]-=limit;
						num[1][i][j]++;
					}
				}

			}
		}
	}
}
int main(){
	init();
	int i,j;
	scanf("%d %d",&n,&k);

//	for(i=1;i<=4;i++){
//		for(j=1;j<=10;j++){
//			printf("%2I64d,",num[0][i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
	if(num[1][k][n]>0){
		printf("%I64d",num[1][k][n]);

		for(i=0;i<=18-log10((double)num[0][k][n])-1;i++){
			printf("0");
		}
		printf("%I64d\n",num[0][k][n]);
	}
	else{
		printf("%I64d\n",num[0][k][n]);
	}
	return 0;
}
