#include <stdio.h>
#include <string.h>

int n;
char op[10];
int x,y,L;
int board[101][101]={0,};
void handle(){
	int i,j;
	if(strcmp(op,"WHITE")==0){
		for(i=x;i<=x+L-1;i++){
			for(j=y;j<=y+L-1;j++){
				if (i<=100 && j<=100){
					board[i][j]=0;
				}
			}
		}
	}
	else if(strcmp(op,"BLACK")==0){
		for(i=x;i<=x+L-1;i++){
			for(j=y;j<=y+L-1;j++){
				if (i<=100 && j<=100){
					board[i][j]=1;
				}
			}
		}
	}
	else {
		int sum=0;
		for(i=x;i<=x+L-1;i++){
			for(j=y;j<=y+L-1;j++){
				if (i<=100 && j<=100){
					if(board[i][j]==1) sum++;
				}
			}
		}
		printf("%d\n",sum);
	}
}

int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%s %d %d %d",&op,&x,&y,&L);
		handle();

	}
	return 0;
}
