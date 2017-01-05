#include <stdio.h>
int c;
char mat[20][20];
int search(int h,int w){
	int i,j;
	int color=mat[h][w];
	int max=-1;

	int tmp=1;
	i=h;
	j=w;
	while((--i)>=0 && mat[i][j]==color) tmp++;
	i=h;
	j=w;
	while((++i)<19 && mat[i][j]==color) tmp++;
	if(tmp==5)return 5;
	max=tmp>max?tmp:max;

	tmp=1;
	i=h;
	j=w;
	while((--j)>=0 && mat[i][j]==color) tmp++;
	i=h;
	j=w;
	while((++j)<19 && mat[i][j]==color) tmp++;
	if(tmp==5)return 5;
	max=tmp>max?tmp:max;

	tmp=1;
	i=h;
	j=w;
	while((--j)>=0 && (++i)<19 && mat[i][j]==color) tmp++;
	j=w;
	i=h;
	while((++j)<19 && (--i)>=0 && mat[i][j]==color) tmp++;
	if(tmp==5)return 5;
	max=tmp>max?tmp:max;

	tmp=1;
	i=h;
	j=w;
	while((--j)>=0 && (--i)>=0 && mat[i][j]==color) tmp++;
	j=w;
	i=h;
	while((++j)<19 && (++i)<19 && mat[i][j]==color) tmp++;
	if(tmp==5)return 5;
	max=tmp>max?tmp:max;

//	printf("i is %d,j is %d,max is %d\n",h,w,max);
	return max;
}
int main(){
	int i,j;
	scanf("%d",&c);
	while(c--){
		for(i=0;i<19;i++){
			for(j=0;j<19;j++){
				scanf("%d",&mat[i][j]);
			}
		}

		for(j=0;j<19;j++){
			for(i=0;i<19;i++){
				if(mat[i][j]==0)continue;
				if(search(i,j)==5){
					printf("%d\n%d %d\n",mat[i][j],i+1,j+1);
					goto HERE;
				}
			}
		}
		printf("0\n");
		HERE:
		continue;

	}
	return 0;
}
