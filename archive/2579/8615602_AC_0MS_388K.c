#include <stdio.h>
int h,w;
char map[10][10];
char mapn[9][9];
char buff[20];

int main(){
	int i,j;
	while(1){
		scanf("%s",&buff);
		if(strcmp(buff,"ENDOFINPUT")==0) break;
		scanf("%d %d",&h,&w);

		for(i=0;i<h;i++){
			scanf("%s",&map[i]);
		}
		memset(mapn,0,81);
		for(i=0;i<h-1;i++){
			for(j=0;j<w-1;j++){
				mapn[i][j]=(map[i][j]+map[i+1][j]+map[i][j+1]+map[i+1][j+1])/4;
			}
		}

		for(i=0;i<h-1;i++){
			printf("%s\n",mapn[i]);
		}


		scanf("%s",&buff);
	}
	return 0;
}
