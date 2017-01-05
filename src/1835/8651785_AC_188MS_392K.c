#include <stdio.h>
#include <string.h>
int c,n;
char dir;
int foot;
int pos[3];
char map[6][6]={0,5,1,0,2,4,2,0,3,5,0,0,4,0,0,1,3,0,0,2,4,0,5,1,5,0,0,2,0,3,1,3,0,4,0,0};
char op[15];
int step;
void handle(){
	switch (op[0]){
		case 'b':{
			dir=dir>=3?(dir-3):(dir+3);
			break;
		}
		case 'l':{
			dir=map[dir][foot];
			break;
		}
		case 'r':{
			dir=map[dir][foot];
			dir=dir>=3?(dir-3):(dir+3);
			break;
		}
		case 'u':{
			dir=foot^dir;
			foot=foot^dir;
			dir=foot^dir;
			dir=dir>=3?(dir-3):(dir+3);
			break;
		}
		case 'd':{
			dir=foot^dir;
			foot=foot^dir;
			dir=foot^dir;
			foot=foot>=3?(foot-3):(foot+3);
			break;
		}
	}
	pos[dir%3]+=step*(1-2*(dir/3));
}
int main(){
	scanf("%d",&c);
	while(c--){
		dir=0;
		foot=5;
		memset(pos,0,12);
		scanf("%d",&n);
		while(n--){
			scanf("%s %d",&op,&step);
			handle();
		}
		printf("%d %d %d %d\n",pos[0],pos[1],pos[2],dir);
	}
	return 0;
}
