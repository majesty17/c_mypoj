#include <stdio.h>
int n;
int M,N;
int a[11][11]={0,};
int main(){
	int i,j;
	for(i=0;i<=10;i++){
		for(j=0;j<=10;j++){
			if(j==0 || i==0){
				a[i][j]=1;
				continue;
			}
			if(i==1 || j==1) a[i][j]=1;
			else if (j>i){
				a[i][j]=a[i][i];
			}
			else{
				a[i][j]=a[i][j-1]+a[i-j][j];
			}
		}
	}
//	for(i=1;i<=10;i++){
//		for(j=1;j<=10;j++){
//			printf("%d,",a[i][j]);
//		}
//		printf("\n");
//	}




	scanf("%d",&n);
	while(n--){
		scanf("%d %d",&M,&N);





		printf("%d\n",a[M][N]);




	}
	return 0;
}
