#include <stdio.h>
#include <stdlib.h>

int h,w;
char **map;
int main(){
	scanf("%d %d",&h,&w);
	map=(char**)malloc(sizeof(char*)*h);
	int i,j;
	for(i=0;i<h;i++){
		map[i]=(char*)malloc(sizeof(char)*w);
		scanf("%s",map[i]);
	}


	int in=0;
	int tris=0;
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){

			if(map[i][j]=='/' || map[i][j]=='\\'){
				tris++;
				in=1-in;

			}
			else if(map[i][j]=='.'){
				if(in==1)
					tris+=2;
			}


		}
	}
	printf("%d",tris/2);



	for(i=0;i<h;i++){
		free(map[i]);
	}
	free(map);
	return 0;
}
