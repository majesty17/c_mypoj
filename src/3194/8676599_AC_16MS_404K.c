#include <stdio.h>
#include <string.h>
char map[100][100];
int n;
char sign[100];
char curr;
void clearMap(int x,int y){
	if(x<0||y<0||x>=n||y>=n)return;
	if(map[x][y]!=curr)return;
	map[x][y]=0;

	clearMap(x-1,y);
	clearMap(x+1,y);
	clearMap(x,y-1);
	clearMap(x,y+1);
}
int main(){
	int i,j,tmpx,tmpy;
	while(1){
		scanf("%d",&n);
		if(n==0)break;
		memset(map,n,10000);
		memset(sign,0,100);

		for(i=0;i<n-1;i++){
			for(j=0;j<n;j++){
				scanf("%d %d",&tmpx,&tmpy);
				map[tmpx-1][tmpy-1]=i+1;
			}
		}


		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(map[i][j]==0)continue;
				if(sign[map[i][j]-1]==1){
//					printf("goto\n");
					goto HERE;
				}
				else {
					curr=map[i][j];
					clearMap(i,j);
					sign[curr-1]=1;
				}
			}
		}
		int sum=0;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				sum+=map[i][j];
			}
		}

		if(sum==0)printf("good\n");
		else {
			HERE:
			printf("wrong\n");
		}


	}
	return 0;
}
