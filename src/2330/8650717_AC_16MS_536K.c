#include <stdio.h>
int N,M;
char map[400][400]={0,};
void drawbox(int l,int b){
	map[b][l]='+';
	map[b][l+4]='+';
	map[b-2][l+6]='+';

	map[b][l+1]='-';
	map[b][l+2]='-';
	map[b][l+3]='-';

	map[b-1][l]='|';
	map[b-2][l]='|';
	map[b-1][l+4]='|';
	map[b-2][l+4]='|';
	map[b-3][l+6]='|';
	map[b-4][l+6]='|';

	map[b-1][l+1]=' ';
	map[b-1][l+2]=' ';
	map[b-1][l+3]=' ';
	map[b-2][l+1]=' ';
	map[b-2][l+2]=' ';
	map[b-2][l+3]=' ';
	map[b-2][l+5]=' ';
	map[b-3][l+5]=' ';

	map[b-1][l+5]='/';

}
void drawhead(int l,int b){
	map[b][l]='+';
	map[b][l+4]='+';
	map[b-2][l+6]='+';
	map[b-2][l+2]='+';


	map[b][l+1]='-';
	map[b][l+2]='-';
	map[b][l+3]='-';

	map[b-2][l+5]='-';
	map[b-2][l+4]='-';
	map[b-2][l+3]='-';



	map[b-1][l+4]=' ';
	map[b-1][l+2]=' ';
	map[b-1][l+3]=' ';


	map[b-1][l+5]='/';
	map[b-1][l+1]='/';
}
void draw(int x,int y,int h){
	int i;
	int left=2*(N-x-1)+4*y;
	int bott=400-2*(N-x);
	for(i=0;i<h;i++){
		drawbox(left,bott-3*i);
	}
	drawhead(left,bott-3*h);
}
int main(){
	int i,j,tmp;
	scanf("%d %d",&N,&M);
	for(i=0;i<400;i++){
		memset(map[i],'.',4*M+2*N+1);
	}
	for(i=0;i<N;i++){
		for(j=0;j<M;j++){
			scanf("%d",&tmp);
			draw(i,j,tmp);
		}
	}




	i=0;
	while(strchr(map[i],'+')==NULL) {
		i++;
		if(i>=400)return;
	}
	for(;i<399;i++){
		puts(map[i]);
	}

	return 0;
}
