#include <stdio.h>
#include <limits.h>
int a[102][102];
int maxa[102][102]={0,};


char height,weight;



int getMax(int a1,int b,int c,int d){

	int m1=a1>b?a1:b;
	int m2=c>d?c:d;
	return m1>m2?m1:m2;
}
int getDeep(char x,char y){
//	short d=0;
	if(maxa[x][y]>0) return maxa[x][y];
	if(a[x][y]<=a[x][y-1] && a[x][y]<=a[x][y+1] && a[x][y]<=a[x-1][y] && a[x][y]<=a[x+1][y]){
		maxa[x][y]=1;
		return 1;
	}

	int u=a[x][y]>a[x-1][y]?getDeep(x-1,y):INT_MIN;
	int d=a[x][y]>a[x+1][y]?getDeep(x+1,y):INT_MIN;
	int l=a[x][y]>a[x][y-1]?getDeep(x,y-1):INT_MIN;
	int r=a[x][y]>a[x][y+1]?getDeep(x,y+1):INT_MIN;
//	maxa[x-1][y]=u;
//	maxa[x+1][y]=d;
//	maxa[x][y-1]=l;
//	maxa[x][y+1]=r;
	int m=getMax(u,d,l,r)+1;
	maxa[x][y]=m<0?1:m;
	//printf("maxa[%d][%d]=%d\n",x,y,maxa[x][y]);
	return maxa[x][y];

}

int main(){
	int i,j;
	int max;
	scanf("%d %d",&height,&weight);
	if(height==0 && weight==0){
		return;
	}
	for(i=0;i<102;i++){
		for(j=0;j<102;j++){
			a[i][j]=0x7fff;
			maxa[i][j]=0;
		}
	}
	for(i=1;i<=height;i++){
		for(j=1;j<=weight;j++){
			scanf("%d",&a[i][j]);
		}
	}



	max=0;
	for(i=1;i<=height;i++){
		for(j=1;j<=weight;j++){

			int tem=getDeep(i,j);	//=(i,j)		//gonna
			max=max<tem?tem:max;
		}
		//printf("\n");
	}

	printf("%d",max);
//
//	for(i=0;i<=height+1;i++){
//		for(j=0;j<=weight+1;j++){
//			printf("%d,",maxa[i][j]);
//		}
//		printf("\n");
//	}

	return 0;
}
