#include <stdio.h>
int h,w;
char mat[101][101];

void clear(int x,int y){
	if(x<0 || y<0 || x>=h || y>=w) return;
	if(mat[x][y]=='.') return ;
	mat[x][y]='.';
	clear(x-1,y);
	clear(x+1,y);
	clear(x-1,y+1);
	clear(x,y+1);
	clear(x+1,y+1);
	clear(x-1,y-1);
	clear(x,y-1);
	clear(x+1,y-1);
}
int main(){
	int i,j;
	scanf("%d%d",&h,&w);
	for(i=0;i<h;i++){
		scanf("%s",&mat[i]);
	}

	int count=0;
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			if(mat[i][j]=='W') count++;
			clear(i,j);
		}
	}


	printf("%d\n",count);

	return 0;
}
