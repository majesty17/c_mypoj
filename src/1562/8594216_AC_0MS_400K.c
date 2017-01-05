#include <stdio.h>
int m,n;
char ch[101][101];
void reduce(int x,int y){
	if(x<0 || y<0 || x>=m || y>=n) return ;

	if(ch[x][y]=='*') return ;

	if(ch[x][y]=='@') ch[x][y]='*';
	reduce(x+1,y);
	reduce(x-1,y);

	reduce(x+1,y+1);
	reduce(x,y+1);
	reduce(x-1,y+1);
	reduce(x+1,y-1);
	reduce(x,y-1);
	reduce(x-1,y-1);
}
int main(){
	int i,j,oil;
	while(1){
		scanf("%d %d",&m,&n);
		if(m==0 && n==0) break;
		oil=0;
		for(i=0;i<m;i++){
			scanf("%s",&ch[i]);
		}

		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				if(ch[i][j]=='@'){
					oil+=1;
					reduce(i,j);
				}
			}
		}


		printf("%d\n",oil);
	}
	return 0;
}
