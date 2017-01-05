#include <stdio.h>
int n;
char mat[100][100];
char sumrow[100];	//每一行加到一起
char sumcol[100];	//每一列加到一起
void handle(){
	int i,j;
	for(i=0;i<n;i++){
		sumrow[i]=0;
		sumcol[i]=0;
		for(j=0;j<n;j++){
			sumrow[i]+=mat[i][j];
			sumcol[i]+=mat[j][i];
		}

//		printf("sumrow[%d]=%d\n",i,sumrow[i]);
//		printf("sumcol[%d]=%d\n",i,sumcol[i]);

	}
	int rowis0=0,colis0=0;
	int x,y;
	for(i=0;i<n;i++){
		if(sumrow[i]%2==1) {rowis0++;x=i;}
		if(sumcol[i]%2==1) {colis0++;y=i;}
	}
	if(colis0==0 && rowis0==0){
		printf("OK\n");
	}
	else if(colis0==1 && rowis0==1){
		printf("Change bit (%d,%d)\n",x+1,y+1);
	}
	else{
		printf("Corrupt\n");
	}

}
int main(){
	int i,j;
	while(1){
		scanf("%d",&n);
		if(n==0)break;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				scanf("%d",&mat[i][j]);
			}
		}
		handle();
	}
	return 0;
}
