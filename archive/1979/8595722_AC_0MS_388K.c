#include <stdio.h>
#include <string.h>

int W,H;
char map[21][21];
int count;

void handle(int x,int y){
//	printf("in handle()\n");
	if(x<0 || y<0 || x>=H || y>=W) return;


	if(map[x][y]=='.' || map[x][y]=='@'){
		count++;
		map[x][y]='#';
		handle(x+1,y);
		handle(x-1,y);
		handle(x,y+1);
		handle(x,y-1);
	}
	else {
		return ;
	}

}
int main(){
	int i,j;
	int manx,many;
	while(1){
		scanf("%d %d",&W,&H);
		if(W==0 && H==0) break;

		for(i=0;i<H;i++){
			scanf("%s",&map[i]);
			char *p=strchr(map[i],'@');
			if(p!=NULL){
				manx=i;many=p-map[i];
			}
		}
		count=0;
//		printf("man x is %d,man y is %d\n",manx,many);
		handle(manx,many);


		printf("%d\n",count);
	}
	return 0;
}
