#include <stdio.h>
__int64 a[101][101];
int N,M;
void handle(){
	int i,j;
	for(i=0;i<=100;i++){
		a[i][0]=1;
		a[i][i]=1;
	}
	for(i=2;i<=100;i++){
		for(j=1;j<i;j++){
			a[i][j]=a[i-1][j]+a[i-1][j-1];
		}
	}

}
int main(){
	handle();
	while(1){
		scanf("%d %d",&N,&M);
		if(N==0 && M==0) break;
		printf("%d things taken %d at a time is %I64d exactly.\n",N,M,a[N][M]);
	}
	return 0;
}
