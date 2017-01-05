#include <stdio.h>
int c;
int x,y;
char map[33][33];
char str[1000];
int main(){
	int i,count=0;
	scanf("%d",&c);
	while(c--){
		scanf("%d %d",&x,&y);
		for(i=0;i<32;i++){
			memset(map[i],'.',32);
		}
		scanf("%s",&str);

		for(i=0;i<strlen(str);i++){
			switch (str[i]){
				case 'E':{
					map[y-1][x]='X';
					x++;
					break;
				}
				case 'W':{
					map[y][x-1]='X';
					x--;
					break;
				}
				case 'N':{
					map[y][x]='X';
					y++;
					break;
				}
				case 'S':{
					map[y-1][x-1]='X';
					y--;
					break;
				}
				default:
					break;
			}
			;
		}




		printf("Bitmap #%d\n",++count);
		for(i=0;i<32;i++){
			printf("%s\n",map[31-i]);
		}
		printf("\n");
	}
	return 0;
}
