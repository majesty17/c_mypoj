#include <stdio.h>
int h,w;
char map[11][11];
char num[11][11];
char buff[11];

char cant[101][20];
int cmp(const char **a,const char **b){
	return strncmp(*a,*b,3);
}
int main(){
	int i,j,count=0;
	int order;
	while(1){
		scanf("%d",&h);
		if(h==0)break;
		scanf("%d",&w);

		for(i=0;i<h;i++){
			scanf("%s",&map[i]);
		}
		memset(num,0,121);
		//write num[][]
		int tmp=0;
		for(i=0;i<h;i++){
			for(j=0;j<w;j++){
				if(map[i][j]=='*')continue;
				if(i==0 || j==0 || map[i-1][j]=='*' || map[i][j-1]=='*') num[i][j]=++tmp;
			}
		}
//		for(i=0;i<h;i++){
//			for(j=0;j<w;j++){
//				printf("%2d,",num[i][j]);
//			}
//			printf("\n");
//		}
		//find
		printf("puzzle #%d:\n",++count);
		printf("Across\n");

		for(i=0;i<h;i++){
			for(j=0;j<w;j++){
				if(map[i][j]=='*')continue;
				memset(buff,0,11);
				order=num[i][j];
				int off=j;
				while(1){
					if(j>=w || map[i][j]=='*')break;
					buff[j-off]=map[i][j];
					j++;
				}
				printf("%3d.%s\n",order,buff);
			}
		}
		printf("Down\n");
		memset(cant,0,2020);
		for(i=0;i<w;i++){
			for(j=0;j<h;j++){
				if(map[j][i]=='*')continue;
				memset(buff,0,11);
				order=num[j][i];
				int off=j;
				while(1){
					if(j>=h || map[j][i]=='*')break;
					buff[j-off]=map[j][i];
					j++;
				}
				sprintf(cant[order],"%3d.%s",order,buff);
			}
		}

		//qsort(cant,si,sizeof(cant[0]),cmp);
		for(i=0;i<=100;i++){
			if(cant[i][0]!='\0')printf("%s\n",cant[i]);
		}
		printf("\n");
	}
	return 0;
}
