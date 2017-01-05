#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int h,w,x,y;
int sum;
char map[21][21]={0,};
char sign;
#define notsign (sign=='X'?'.':'X')
void doit(int d1,int d2){
	if(d1<0 || d2<0 || d1>h-1 || d2>w-1 || map[d1][d2]!=sign)return;
	map[d1][d2]='\0';

	if(d1==0 || map[d1-1][d2]==notsign)sum+=1;
	if(d1==h-1 || map[d1+1][d2]==notsign)sum+=1;
	if(d2==0 || map[d1][d2-1]==notsign)sum+=1;
	if(d2==w-1 || map[d1][d2+1]==notsign)sum+=1;


	doit(d1-1,d2);
	doit(d1+1,d2);

	doit(d1,d2-1);
	doit(d1,d2+1);

	doit(d1-1,d2-1);
	doit(d1-1,d2+1);
	doit(d1+1,d2-1);
	doit(d1+1,d2+1);
}
int main(){
	int i,j;
	while(1){
		scanf("%d %d %d %d",&h,&w,&x,&y);
		if(h==0 && w==0)break;
		sum=0;
		for(i=0;i<h;i++){
			scanf("%s",map[i]);
		}
		sign=map[x-1][y-1];
		doit(x-1,y-1);
		printf("%d\n",sum);
	}
}
