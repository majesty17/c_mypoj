#include <stdio.h>
#define DRY 0
#define WET 1
#define DONE 2
int N,M,K;
char lake[101][101]={DRY,};

int max=-1;
int getSize(int x,int y){
	if(x<1 || y<1 || x>N || y>M || lake[x][y]!=WET) return 0;

	lake[x][y]=DONE;
	return 1+getSize(x+1,y)+getSize(x-1,y)+getSize(x,y+1)+getSize(x,y-1);
}

int main(){
	int i,j,tem1,tem2;
	scanf("%d %d %d",&N,&M,&K);
	for(i=0;i<K;i++){
		scanf("%d %d",&tem1,&tem2);
		lake[tem1][tem2]=WET;
	}

	for(i=1;i<=N;i++){
		for(j=1;j<=M;j++){
			if(lake[i][j]==0) continue;

			int m=getSize(i,j);
			max=max>m?max:m;
		}
	}

	printf("%d\n",max);

	return 0;
}
