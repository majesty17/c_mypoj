#include <stdio.h>
int N,S;
int num[20][20];
void putsspace(int n){
	int i;
	for(i=0;i<n;i++){
		printf(" ");
	}
}
int main(){
	int i,j;
	scanf("%d %d",&N,&S);
	for(i=0;i<N;i++){
		for(j=i;j<N;j++){
			num[i][j]=(S-1+((j+1)*j/2+i)%9)%9+1;
		}
	}

	for(i=0;i<N;i++){
		putsspace(i*2);
		for(j=i;j<N;j++){

			printf("%d",num[i][j]);
			if(j<N-1) printf(" ");
		}
		printf("\n");
	}



	return 0;
}
