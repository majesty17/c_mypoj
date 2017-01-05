#include <stdio.h>
int w,h;
int cuts;
int x01,y01,x02,y02;
__int64 map[21][21];
__int64 curr;
void handle(int x,int y){
	map[x][y]=-1;
	if(x>=1 && map[x-1][y]==curr) handle(x-1,y);
	if(y>=1 && map[x][y-1]==curr) handle(x,y-1);
	if(x<h-1 && map[x+1][y]==curr) handle(x+1,y);
	if(y<w-1 && map[x][y+1]==curr) handle(x,y+1);
}
int main(){
	int i,j,count;
	while(1){
		scanf("%d %d",&h,&w);
		if(w==0 && h==0) break;
		scanf("%d",&cuts);
		memset(map,0,21*21*sizeof(map[0][0]));
		while(cuts--){
			scanf("%d %d %d %d",&x01,&y01,&x02,&y02);
			//gonna cut
			if(x01>x02){
				x01=x01^x02;
				x02=x01^x02;
				x01=x01^x02;
			}
			if(y01>y02){
				y01=y01^y02;
				y02=y01^y02;
				y01=y01^y02;
			}
			for(i=x01;i<x02;i++){
				for(j=y01;j<y02;j++){
					map[j][i]|=1<<cuts;
				}
			}
		}
		//gonna count
		count=0;
		for(i=0;i<h;i++){
			for(j=0;j<w;j++){
				if(map[i][j]==-1) continue;
				else{
					count++;
					curr=map[i][j];
					handle(i,j);
				}
			}
		}
		printf("%d\n",count);
	}
	return 0;
}
