#include <stdio.h>
int cases;
int k;
int T[302];
int W[301];
int handle(){
	int i;
	W[0]=0;
	for(i=1;i<=301;i++){
		T[i]=((1+i)*i)/2;
	}
	for(i=1;i<=300;i++){
		W[i]=W[i-1]+i*T[i+1];
	}

}
int main(){
	handle();
	int i,count=0;
	scanf("%d",&cases);
	while(cases--){
		scanf("%d",&k);
		printf("%d %d %d\n",++count,k,W[k]);
	}
	return 0;
}
