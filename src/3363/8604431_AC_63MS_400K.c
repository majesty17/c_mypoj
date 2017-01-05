#include <stdio.h>
char map[101][101];
int n,m,r,c;
void draw(int x,int y){
	int i,j;
	for(i=x;i<x+r;i++){
		for(j=y;j<y+c;j++){
			if(map[i][j]=='0') map[i][j]='1';
			else map[i][j]='0';
		}
	}
}
int main(){
	int i,j;
	while(1){
		scanf("%d %d %d %d",&n,&m,&r,&c);
		if(n==0&&m==0&&r==0&&c==0) break;
		for(i=0;i<n;i++){
			scanf("%s",&map[i]);
		}
		int mindraw=0;
		for(i=0;i<=n-r;i++){
			for(j=0;j<=m-c;j++){
				if(map[i][j]=='1'){
					mindraw++;
					draw(i,j);
				}
			}
		}

//		for(i=0;i<n;i++){
//			for(j=0;j<m;j++){
//				printf("%c,",map[i][j]);
//			}
//			printf("\n");
//		}

		int sign=0;
		for(i=n-1;i>n-1-r;i--){
			for(j=m-1;j>m-1-c;j--){
				if(map[i][j]!='0') sign=1;
			}
		}


		if(sign==1) printf("-1\n");
		else printf("%d\n",mindraw);
	}
	return 0;
}
