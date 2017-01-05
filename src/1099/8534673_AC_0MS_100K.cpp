#include <stdio.h>
#define LU 1		//左上
#define LD 2		//左下
#define RU 3		//右上
#define RD 4		//右下

#define UD 5		//上下
#define LR 6		//左右

int a[11][11],n,count;
int b[11][11]={0,};

void makeB(){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(a[i][j]==1){
				b[i][j]=LR;
				continue;
			}
			if(a[i][j]==-1){
				b[i][j]=UD;
				continue;
			}
			if(i==0){						//处理第一行
				if(j==0){						//第一行第一个
					b[i][j]=LD;
					continue;
				}
				else{							//第一行其他
					switch (b[i][j-1]){
						case LD:{
							b[i][j]=LD;
							break;
						}
						case LR:{
							b[i][j]=RD;
							break;
						}
						case RD:{
							b[i][j]=RD;
							break;
						}
					}
				}
				continue;
			}
			else{
				if(j==0){
					if(b[i-1][j]!=LD && b[i-1][j]!=RD && b[i-1][j]!=UD){
						b[i][j]=LU;
					}else{
						b[i][j]=LD;
					}
				}
				else{
					if(b[i-1][j]!=LD && b[i-1][j]!=RD && b[i-1][j]!=UD){
						if(b[i][j-1]!=LR && b[i][j-1]!=RU &&b[i][j-1]!=RD ){
							b[i][j]=LU;
						}
						else{
							b[i][j]=RU;
						}
					}
					else{
						if(b[i][j-1]!=LR && b[i][j-1]!=RU &&b[i][j-1]!=RD ){
							b[i][j]=LD;
						}
						else{
							b[i][j]=RD;
						}
					}
				}
			}
		}
	}
}

void writeLine(int n){
	int i;
	for(i=0;i<n*4+3;i++){
		printf("*");
	}
	printf("\n");
}
void writeH(int n){
	int i;
	printf("*");
	for(i=0;i<n;i++){
		printf("  H ");
	}
	printf(" *\n");
}
void handle(){
	printf("Case %d:\n\n",count);
	writeLine(n);
	makeB();
	int i,j;





	for(i=0;i<n;i++){
		if(i==0){
			printf("*H");
			for(j=0;j<n;j++){
				if(b[i][j]==LR){
					printf("-O-H");
				}
				else if (b[i][j]==LU || b[i][j]==LD){
					printf("-O H");
				}
				else if(b[i][j]==UD){
					printf(" O H");
				}
				else if(b[i][j]==RU || b[i][j]==RD){
					printf(" O-H");
				}
			}

			printf("*\n");
			printf("* ");
			for(j=0;j<n;j++){
				if(b[i][j]==LD || b[i][j]==UD || b[i][j]==RD){
					printf(" |  ");
				}else{
					printf("    ");
				}
			}
			printf("*\n");
		}
		else if(i==n-1){
			printf("* ");
			for(j=0;j<n;j++){
				if(b[i][j]==LU || b[i][j]==UD || b[i][j]==RU){
					printf(" |  ");
				}else{
					printf("    ");
				}
			}
			printf("*\n");
			printf("*H");
			for(j=0;j<n;j++){
				if(b[i][j]==LR){
					printf("-O-H");
				}
				else if (b[i][j]==LU || b[i][j]==LD){
					printf("-O H");
				}
				else if(b[i][j]==UD){
					printf(" O H");
				}
				else if(b[i][j]==RU || b[i][j]==RD){
					printf(" O-H");
				}
			}

			printf("*\n");
		}
		else{
			printf("* ");
			for(j=0;j<n;j++){
				if(b[i][j]==LU || b[i][j]==UD || b[i][j]==RU){
					printf(" |  ");
				}else{
					printf("    ");
				}
			}
			printf("*\n");
			printf("*H");
			for(j=0;j<n;j++){
				if(b[i][j]==LR){
					printf("-O-H");
				}
				else if (b[i][j]==LU || b[i][j]==LD){
					printf("-O H");
				}
				else if(b[i][j]==UD){
					printf(" O H");
				}
				else if(b[i][j]==RU || b[i][j]==RD){
					printf(" O-H");
				}
			}

			printf("*\n");
			printf("* ");
			for(j=0;j<n;j++){
				if(b[i][j]==LD || b[i][j]==UD || b[i][j]==RD){
					printf(" |  ");
				}else{
					printf("    ");
				}
			}
			printf("*\n");
		}
		if(i<n-1) writeH(n);


	}




	writeLine(n);
	printf("\n");


}
int main(){
	int i,j;
	count=0;
	while(1){

		scanf("%d",&n);						//get n
		if(n==0) break;
		count++;
		for(i=0;i<n;i++){					//get a[n][n]
			for(j=0;j<n;j++){
				scanf("%d",&a[i][j]);
			}
		}



		handle();


	}



}
