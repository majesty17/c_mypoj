#include <stdio.h>
char mat[101][101];
char sign[101];
int n;
int ciszero(int c){
	int i;
	int ret=1;
	for(i=0;i<n;i++){
		if(mat[i][c]==1) ret=0;
	}
	return ret;
}
int rputzero(int r){
	int i;
	int ret=1;
	for(i=0;i<n;i++){
		mat[r][i]=0;
	}
}
int main(){
	int i,j,tem;
	scanf("%d",&n);
	memset(mat,0,101*101);
	memset(sign,0,101);
	for(i=0;i<n;i++){
		while(1){
			scanf("%d",&tem);
			if(tem==0) break;
			mat[i][tem-1]=1;

		}

	}
//	for(i=0;i<n;i++){
//		for(j=0;j<n;j++){
//			printf("%d,",mat[i][j]);
//		}
//		printf("\n");
//	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(sign[j]==0 && ciszero(j)==1){
				rputzero(j);
				sign[j]=1;
				printf("%d ",j+1);
				break;
			}
		}
	}


	return 0;
}
