#include <stdio.h>
int n;
char map[729][729];
char buffer[730];
int pow3(int up){
	int ret=1;
	while(--up){
		ret*=3;
	}
	return ret;
}
int itworks(int x,int y){
	int i;
	for(i=1;i<=8;i++){
		if((x/pow3(i)+y/pow3(i))%2==1) return 0;
	}


	return 1;

}

void init(){
	int i,j;
	for(i=0;i<729;i++){
		for(j=0;j<729;j++){
//			if( itworks(i,j)==1 ){
			if( (i+j)%2==0 && (i/3+j/3)%2==0 && (i/9+j/9)%2==0 && (i/27+j/27)%2==0 && (i/81+j/81)%2==0 && (i/243+j/243)%2==0 ){
				map[i][j]='X';
			}
			else{
				map[i][j]=' ';
			}
		}
	}
}
int main(){

	int i,j;
	init();
	while(1){
		scanf("%d",&n);
		if(n==-1) break;
		if(n==0){
			printf("-\n");
			continue;
		}
		memset(buffer,0,730);
		for(i=0;i<pow3(n);i++){
			strncpy(buffer,map[i],pow3(n));

			printf("%s\n",buffer);
		}
		printf("-\n");

	}
	return 0;
}
