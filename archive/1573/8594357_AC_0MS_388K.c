#include <stdio.h>
int m,n,pos;
char map[12][12];
char sign[12][12];
int main(){
	while(1){
		int i,j;
		scanf("%d %d %d",&m,&n,&pos);
		if(0==m && 0==n && 0==pos) break;
		memset(sign,0,144);
		memset(map,0,144);
		for(i=1;i<=m;i++){
			scanf("%s",&(map[i][1]));
		}
		i=1;j=pos;
		int step=0;
		while(1){

			if(i<1 || j<1 || i>m || j>n){
				step++;
				sign[i][j]=step;
				printf("%d step(s) to exit\n",sign[i][j]-1);
				break;
			}

			if(sign[i][j]==0){
				step++;
				sign[i][j]=step;
			}
			else{


				printf("%d step(s) before a loop of %d step(s)\n",sign[i][j]-1,step-sign[i][j]+1);
				break;
			}

			switch (map[i][j]){
				case 'N':{
					i--;
					break;
				}
				case 'S':{
					i++;
					break;
				}
				case 'E':{
					j++;
					break;
				}
				case 'W':{
					j--;
					break;
				}
				default:
					break;
			}

		}





	}
	return 0;
}
