///0 灯灭
///1 灯亮

///0 不按
///1 按

///要全灭

#include <stdio.h>
char a[5*100][6]={0,};
char b[5][6]={0,};

void search(int round){
	int i,j,k;


	for(i=0;i<2<<5;i++){
//	for(i=11;i<12;i++){
		b[0][0]=(i>>0)&1;
		b[1][0]=(i>>1)&1;
		b[2][0]=(i>>2)&1;
		b[3][0]=(i>>3)&1;
		b[4][0]=(i>>4)&1;
//		printf("%d%d%d%d%d\n",b[0][0],b[1][0],b[2][0],b[3][0],b[4][0]);

		for(j=1;j<6;j++){
			if(j==1){
				b[0][j]=(b[0][j-1]+a[round*5][j-1]+b[1][j-1])%2;
				b[1][j]=(b[1][j-1]+a[round*5+1][j-1]+b[0][j-1]+b[2][j-1])%2;
				b[2][j]=(b[2][j-1]+a[round*5+2][j-1]+b[1][j-1]+b[3][j-1])%2;
				b[3][j]=(b[3][j-1]+a[round*5+3][j-1]+b[2][j-1]+b[4][j-1])%2;
				b[4][j]=(b[4][j-1]+a[round*5+4][j-1]+b[3][j-1])%2;
			}else{
				b[0][j]=(b[0][j-2]+b[0][j-1]+a[round*5][j-1]+b[1][j-1])%2;
				b[1][j]=(b[1][j-2]+b[1][j-1]+a[round*5+1][j-1]+b[0][j-1]+b[2][j-1])%2;
				b[2][j]=(b[2][j-2]+b[2][j-1]+a[round*5+2][j-1]+b[1][j-1]+b[3][j-1])%2;
				b[3][j]=(b[3][j-2]+b[3][j-1]+a[round*5+3][j-1]+b[2][j-1]+b[4][j-1])%2;
				b[4][j]=(b[4][j-2]+b[4][j-1]+a[round*5+4][j-1]+b[3][j-1])%2;
			}

		}


		if(	a[round*5][5]==(b[0][4]+b[0][5]+b[1][5])%2 &&
			a[round*5+1][5]==(b[1][4]+b[1][5]+b[0][5]+b[2][5])%2 &&
			a[round*5+2][5]==(b[2][4]+b[2][5]+b[1][5]+b[3][5])%2 &&
			a[round*5+3][5]==(b[3][4]+b[3][5]+b[2][5]+b[4][5])%2 &&
			a[round*5+4][5]==(b[4][4]+b[4][5]+b[3][5])%2
			){
			break;
		}
//		printf("not ok yet\n");

	}

	printf("PUZZLE #%d\n",round+1);
	for(i=0;i<5;i++){
		for(j=0;j<6;j++){
			printf("%d",b[i][j]);
			if(j<5) printf(" ");
		}
		printf("\n");
	}

}
int main(){
	int n;
	scanf("%d",&n);
	int i,j;


	for(i=0;i<n*5;i++){
		for(j=0;j<6;j++){
			scanf("%d",&a[i][j]);
		}
	}

	for(i=0;i<n;i++){
		search(i);
	}




	return 0;
}
