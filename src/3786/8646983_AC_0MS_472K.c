#include <stdio.h>
int c,n,k,order;
int num[101][101][2]={0,};
void make(){
	int i,j;
	num[1][0][0]=1;
	num[1][0][1]=0;

	num[2][0][0]=2;
	num[2][0][1]=1;
	num[2][1][0]=0;
	num[2][1][1]=1;
	for(i=3;i<=100;i++){
		for(j=0;j<=i-1;j++){
			num[i][j][0]=num[i-1][j][0]+num[i-1][j][1];
			num[i][j][1]=num[i-1][j][0]+num[i-1][j-1][1];
		}
	}
}
int main(){
	make();
	int i;
	scanf("%d",&c);
	while(c--){
		scanf("%d %d %d",&order,&n,&k);
		printf("%d %d\n",order,num[n][k][0]+num[n][k][1]);
	}
	return 0;
}
